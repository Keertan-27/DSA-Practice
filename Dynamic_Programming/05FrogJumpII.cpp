#include <iostream>
#include <vector>
using namespace std;

int solve(int idx, vector<int> heights, int k, vector<int> dp)
{
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (idx - j >= 0)
        {
            int steps = solve(idx - j, heights, k, dp) + abs(heights[idx] - heights[idx - j]);
            minSteps = min(minSteps, steps);
        }
    }
    return dp[idx] = minSteps;
}
int minJump(vector<int> heights, int k)
{
    int n = heights.size();
    vector<int> dp(n, -1);

    return solve(n - 1, heights, k, dp);
}

int minJumpTabulation(vector<int> heights, int k)
{
    int n = heights.size();
    vector<int> dp(n);
    if(n == 1) return 0;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if(i-j >=0){
                int steps = dp[i - j] + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, steps);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}

int main()
{
    vector<int> heights = {10, 5, 20, 0, 15};
    int k = 2;
    cout << minJumpTabulation(heights, k);
    return 0;
}