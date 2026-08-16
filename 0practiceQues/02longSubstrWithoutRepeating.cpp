#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int lonSubstrWithoutRepeating(string s)
{
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        unordered_set<char> st;
        int len = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (st.find(s[j]) != st.end())
            {
                break;
            }
            maxLen = max(maxLen, j-i+1);
            st.insert(s[j]);
        }
    }

    return maxLen;
}

int longSubstrOptimal(string s)
{
    int left = 0;
    int maxLen = 0;
    unordered_map<char, int> mp;
    for (int right = 0; right < s.size(); right++)
    {
        if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left)
        {
            left = mp[s[right]] +1;
        }
        mp[s[right]] = right;
        maxLen = max(maxLen, right - left +1);
    }
    return maxLen;
}
int main()
{
    string s = "cadbzabcd";
    cout << lonSubstrWithoutRepeating(s);
    return 0;
}