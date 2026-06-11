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
int main()
{
    string s = "babad";
    string ans = longestPalindromicSubstring(s);
    cout<<ans;
    return 0;
}