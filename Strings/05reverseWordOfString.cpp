#include <iostream>
#include <string>
using namespace std;

string reverseWord(string s)
{
    string ans;
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++)
    {
        string word = "";
        while (i < s.size() && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());
        if(word.length() > 0)
            ans += " " + word;
    }
    return ans.substr(1);
}
int main()
{
    string s = "the moon star";
    string ans = reverseWord(s);
    cout<<ans;
    return 0;
}