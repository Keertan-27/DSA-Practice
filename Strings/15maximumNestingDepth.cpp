#include<iostream>
#include<string>
using namespace std;

int maxNestingDepth(string s)
{
    int val = 0, maxVal = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '('){
            val++;
            maxVal = max(maxVal, val);
        }
        else if (s[i] == ')')
            val--;
    }
    return maxVal;
}
int main()
{
    string s = "()(())((()()))";
    string s1 = "(1)+((2))+(((3)))";
    int ans = maxNestingDepth(s);
    cout<<ans;
    return 0;
}