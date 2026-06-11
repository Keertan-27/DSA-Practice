#include <iostream>
#include <string>
using namespace std;
string longestPalindromicSubstring(string s)
{
    string longest;
    int i = 0, j = s.size() - 1;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string subStr = s.substr(i, j-i+1);

            string rev = subStr;
            reverse(rev.begin(), rev.end());

            if(subStr == rev && subStr.size() > longest.size()){
                longest = subStr;
            }
        }
    }
    return longest;
}

string longestPalindromicSubstringOptimal(string s)
{
    int n = s.size();
    int maxLen = 1;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        // odd palindrome
        int left = i, right = i;
        while (left>=0 && right < n && s[left] == s[right])
        {
            int len = right - left +1;
            if(len > maxLen){
                maxLen = len;
                start = left;
            }
            left--;
            right++;
        }

        // even palindrome
        left = i, right = i+1;
        while (left>=0 && right < n && s[left] == s[right])
        {
            int len = right -left+1;
            if (len > maxLen)
            {
                maxLen = len;
                start = left;
            }
            left--;
            right++;
        }
    }
    return s.substr(start, maxLen);
}
int main()
{
    string s = "babbad";
    string ans = longestPalindromicSubstringOptimal(s);
    cout<<ans;
    return 0;
}