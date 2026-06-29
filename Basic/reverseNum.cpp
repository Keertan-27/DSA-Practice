#include <iostream>
using namespace std;
int reverseVal(int x)
{
    int rev = 0;
    while (x != 0)
    {
        int digit = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
            return false;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
            return false;

        rev = rev * 10 + digit;
    }
    return rev;
}

int main()
{
    int num = -13375;
    int ans = reverseVal(num);
    cout << ans;
    return 0;
}