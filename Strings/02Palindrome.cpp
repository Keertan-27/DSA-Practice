#include <iostream>
#include <string>
using namespace std;
// little slower
bool isPalindrome(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    if (rev == s)
        return true;
    return false;
}
// more faster
bool isAlphaNumeric(char ch)
{
    if ((ch >= '0' && ch <= '9') || tolower(ch) >= 'a' && tolower(ch) <= 'z')
        return true;

    return false;
}
bool isPalindromeConditions(string s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        if (!isAlphaNumeric(s[left]))
        {
            left++;
            continue;
        }
        if (!isAlphaNumeric(s[right]))
        {
            right--;
            continue;
        }

        if (tolower(s[left]) != tolower(s[right]))
            return false;

        left++, right--;
    }

    return true;
}
int main()
{
    string s = "Mada&m";
    cout << isPalindromeConditions(s);
    return 0;
}