#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sumOfBeautyOfAllSubstrings(string s)
{
    int sumBeauty = 0;
    for (int i = 0; i < s.size(); i++)
    {
        vector<int> freq(26, 0);
        for (int j = i; j < s.size(); j++)
        {
            freq[s[j] - 'a']++;

            int minfreq = INT_MAX, maxfreq = 0;

            for (int k = 0; k < 26; k++)
            {
                if (freq[k] > 0)
                {
                    minfreq = min(minfreq, freq[k]);
                    maxfreq = max(maxfreq, freq[k]);
                }
            }
            sumBeauty += (maxfreq - minfreq);
        }
    }
    return sumBeauty;
}
int main()
{
    string s = "aabcbaa";
    int ans = sumOfBeautyOfAllSubstrings(s);
    cout << ans;
    return 0;
}