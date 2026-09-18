#include <iostream>
#include <vector>
using namespace std;

int f(int i, vector<int> &nums, vector<int> &dp)
{
    if (i == 0)
        return nums[0];
    if (i == 1)
        return max(nums[0], nums[1]);

    if (dp[i] != -1)
        return dp[i];
    return dp[i] = max(f(i - 1, nums, dp), f(i - 2, nums, dp) + nums[i]);
}

int robDP(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> temp1, temp2;
    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            temp1.push_back(nums[i]);
        if (i != 0)
            temp2.push_back(nums[i]);
    }
    return max(f(n - 2, temp1, dp1), f(n - 2, temp2, dp2));
}

int maxRob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }

    return max(maxRob(temp1), maxRob(temp2));
}

int main()
{
    vector<int> nums = {2, 3, 2};
    cout << rob(nums);
    return 0;
}