#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeBasedOnSign(vector<int> nums)
{
    vector<int> posArr;
    vector<int> negArr;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i]>0)
            posArr.push_back(nums[i]);
        else
            negArr.push_back(nums[i]);
    }


    for (int i = 0; i < posArr.size(); i++)
    {
        nums[i*2] = posArr[i];
        nums[i*2 +1] = negArr[i];
    }
    return nums;
}

vector<int> rearrangeBasedOnSizeOptimal(vector<int> nums)
{
    int indPos = 0, indNeg = 1;
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans[indPos] = nums[i];
            indPos += 2;
        }else{
            ans[indNeg] = nums[i];
            indNeg += 2;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {3,-1,2,5,-2,-8};
    vector<int> ans = rearrangeBasedOnSizeOptimal(arr);
    
    for (int x:ans)
    {
        cout<<x<<" ";
    }
    
    return 0;
}