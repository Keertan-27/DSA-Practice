#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= nums.size(); i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
    return -1;
}

int missingNumberMp(vector<int> &nums)
{
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }
    for (int i = 0; i <= nums.size(); i++)
    {
        if(st.find(i) == st.end())
            return i;
    }
    
    return -1;
}

int missingNumberNNum(vector<int> &nums)
{
    int n = nums.size();
    int sumN = (n * (n+1))/2;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i]; 
    }
    return sumN - sum;
}
int main()
{
    vector<int> nums = {0,1,4,2,3};
    cout<<missingNumberNNum(nums);
    return 0;
}
