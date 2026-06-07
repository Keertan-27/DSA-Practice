#include<iostream>
#include<string>
using namespace std;
string removeOuterMostParantheses(string s)
{
    int depth = 0;
    string ans;

    for(char ch : s)
    {
        if (ch == '(')
        {
            if (depth>0)
                ans += ch;
            depth++;
        }
        else{
            depth--;
            if (depth > 0)
                ans += ch;
        }
    }
    return ans;
}
int main()
{
    string s = "(()())(())";
    string ans = removeOuterMostParantheses(s);
    cout<<ans;
    return 0;
}