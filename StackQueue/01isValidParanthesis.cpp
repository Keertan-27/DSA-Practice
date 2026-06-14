#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
            st.push(s[i]);

        else
        {
            if(st.empty())
                return false;
            char rem = st.top();
            if ((rem == '{' && s[i] != '}') || (rem == '[' && s[i] != ']') || (rem == '(' && s[i] != ')'))
                return false;

            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    string s = "((";
    bool ans = isValid(s);
    cout << ans;
    return 0;
}