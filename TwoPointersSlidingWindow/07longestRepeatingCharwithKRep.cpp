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
            else break;
        }
    }
    return maxLen;
}

int main()
{
    string s = "AABABBA";
    int ans = longestRepeatingCharWithKRepBrut(s, 2);
    cout << ans;
    return 0;
}