#include <iostream>
#include <string>
using namespace std;

string removeAllOccurance(string s, string part)
{
    while (s.length() > 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    string ans = removeAllOccurance(s, part);
    cout<< ans;
    return 0;
}