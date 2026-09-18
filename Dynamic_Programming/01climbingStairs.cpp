#include <iostream>
#include <vector>
#include <string>
using namespace std;

int climbStairsRecursion(int n)
{
    if (n == 1 || n == 2)
        return n;

    return climbStairsRecursion(n - 1) + climbStairsRecursion(n - 2);
}
int climbStairsDP(int n, vector<int> &dp)
{
    if (n == 1 || n == 2)
    {
        return n;
    }
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = climbStairsDP(n - 1, dp) + climbStairsDP(n - 2, dp);
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return climbStairsDP(n, dp);
}

int climbStairsTabulation(int n)
{
    if (n <= 2)
        return n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int climbStairsTabulationSpaceOptimized(int n)
{
    if (n <= 2)
        return n;
    int prev2 = 1;
    int prev1 = 2;
    int result;
    for (int i = 3; i <= n; i++)
    {
        result = prev1 + prev2;
        prev2 = prev1;
        prev1 = result;
    }
    return result;
}
int main()
{
    int n = 6;
    cout << climbStairsTabulationSpaceOptimized(n);
    return 0;
}