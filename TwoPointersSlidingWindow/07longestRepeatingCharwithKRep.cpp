#include <iostream>
#include <string>
using namespace std;

int longestRepeatingCharWithKRepBrut(string s, int K)
{
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int hasArray[26] = {0};
        int maxfreq = 0;
        for (int j = i; j < s.size(); j++)
        {
            hasArray[s[j] - 'A']++;
            maxfreq = max(maxfreq, hasArray[s[j] - 'A']);
            int change = (j - i + 1) - maxfreq;
            if (change <= K)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
                break;
        }
    }
    return maxLen;
}

int longestRepeatingCharWithKRepBetter(string s, int K)
{
    int maxLen = 0;
    int maxfreq = 0;
    int left = 0, right = 0;
    int hasArray[26] = {0};
    while (right < s.length())
    {
        hasArray[s[right] - 'A']++;
        maxfreq = max(maxfreq, hasArray[s[right] - 'A']);

        while ((right - left + 1) - maxfreq > K)
        {
            hasArray[s[left] - 'A']--;
            maxfreq = 0;
            for (int i = 0; i < 26; i++)
            {
                maxfreq = max(maxfreq, hasArray[i]);
                left++;
            }
        }

        if ((right - left + 1) - maxfreq <= K)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }

    return maxLen;
}

int main()
{
    string s = "AABABBA";
    int ans = longestRepeatingCharWithKRepBetter(s, 2);
    cout << ans;
    return 0;
}