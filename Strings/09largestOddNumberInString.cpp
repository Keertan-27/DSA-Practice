#include<iostream>
#include<string>
using namespace std;
string largestOddnumInString(string s)
{
    int n = s.size();
    for (int i = n-1; i>=0; i--)
    {
        if ((s[i] - '0') % 2 == 1)
        {
            return s.substr(0, i+1);
        }
    }
    return "";
    
}
int main()
{
    string s = "368718";
    string s1 = "4262";
    string ans = largestOddnumInString(s1);
    cout<<ans;
    return 0;
}