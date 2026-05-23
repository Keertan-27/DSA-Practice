#include<iostream>
#include<string>
#include<map>
using namespace std;

int longestSubstringWithAtmostKCharacter(string s, int K)
{
    int right = 0, left = 0;
    int maxLen=0;
    unordered_map <char, int> mp;
    while (right<s.size())
    {
        mp[s[right]]++;
        if(mp.size()>K)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0) 
                mp.erase(s[left]);
            left++;
        }
        if (mp.size()<=K)
            maxLen = max(maxLen, right-left+1);
        right++;
    }
    return maxLen;
}

int main()
{
    string s = "aaabbbccccd";
    int ans = longestSubstringWithAtmostKCharacter(s, 2);
    cout<<ans;
    return 0;
}