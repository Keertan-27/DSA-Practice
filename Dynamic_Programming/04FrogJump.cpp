#include <iostream>
#include <vector>
using namespace std;

int minJumpRec(int i, vector<int> &heights)
{
    if (i == 0)
        return 0;
    int prev1 = minJumpRec(i - 1, heights) + abs(heights[i] - heights[i - 1]);
    int prev2 = INT_MAX;
    if (i > 1)
        prev2 = minJumpRec(i - 2, heights) + abs(heights[i] - heights[i - 2]);
    return min(prev1, prev2);
}
int minJump(vector<int> heights)
{
    int n = heights.size();
    if (n == 1)
        return 0;
    return minJumpRec(n - 1, heights);
}

int minJumpRecDp(int i, vector<int> &heights, vector<int> &dp)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int prev1 = minJumpRecDp(i - 1, heights, dp) + abs(heights[i] - heights[i - 1]);
    int prev2 = INT_MAX;
    if (i > 1)
        prev2 = minJumpRecDp(i - 2, heights, dp) + abs(heights[i] - heights[i - 2]);
    return dp[i] = min(prev1, prev2);
}
int minJumpDp(vector<int> heights)
{
    int n = heights.size();
    if (n == 1)
        return 0;
    vector<int> dp(n, -1);
    return minJumpRecDp(n - 1, heights, dp);
}

int minJumpDpTabulation(vector<int> heights)
{
    int n = heights.size();
    if (n == 1)
        return 0;
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(heights[0] - heights[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]),
                    dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }
    return dp[n-1];
}

int main()
{
    vector<int> heights = {30, 20, 50, 10, 40};
    cout << minJumpDpTabulation(heights);
    return 0;
}