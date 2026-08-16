#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i+1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}

vector<int> twoSumOptimal(vector<int> nums,int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int remain = target - nums[i];
        if (!mp.empty() && mp.find(remain) != mp.end())
        {
            return {mp[remain], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}
int main()
{
    vector<int> arr = {2,7,11,15};
    vector<int> ans = twoSumOptimal(arr, 26);
    for (int x : ans)
    {
        cout<< x << " ";
    }
    return 0;
}