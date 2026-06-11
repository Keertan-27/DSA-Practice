#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int stringToInteger(string s)
{
    int i = 0, n = s.size();

    while (i < n && s[i] == ' ')
        i++;
    
    int sign = 1;
    if (i<n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }

    int nums = 0;
    while (i<n && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        //overflow check
        if(nums > INT_MAX/10 || (nums == INT_MAX/10 && digit > 7)){
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        nums = nums * 10 + digit;
        i++;
    }
    
    return sign * nums;
}
int main()
{
    string s = "  -1337c0d3";
    int ans = stringToInteger(s);
    cout<<ans;
    return 0;
}