#include<iostream>
#include<vector>
using namespace std;
int f(int i, vector<int> &nums, vector<int> &dp)
{
    if (i == 0)
        return nums[0];
    if(i == 1)
        return max(nums[0], nums[1]);
    
    if(dp[i] != -1) return dp[i];
    return dp[i] = max(f(i-1, nums, dp), f(i-2, nums, dp) + nums[i]);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if(n ==1) return nums[0];
    vector<int> dp(n, -1);
    return f(n-1, nums, dp);
}


int robDP(vector<int> &nums)
{
    int n = nums.size();
    if(n ==1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    
    return dp[n-1];
}

int robDpSpaceOptm(vector<int> &nums)
{
    int n = nums.size();
    if(n ==1) return nums[0];
    // vector<int> dp(n);
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

int main()
{
    vector<int> nums = {2,1,1,5};
    cout<< robDpSpaceOptm(nums);
    return 0;
}