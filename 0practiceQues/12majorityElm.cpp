#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int majorityElm(vector<int>& nums)
{
    int n = nums.size();
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
        if(mpp[nums[i]] > n/2){
            return nums[i];
        }
    }
    return 0;
}

int majorityElmOpt(vector<int>& nums)
{
    int n = nums.size();
    int elm = nums[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != elm)
        {
            cnt--;
            if (cnt == 0)
            {
                elm = nums[i];
            }
            
        }else{
            cnt++; 
        }
    }
    return elm;
}
int main()
{
    vector<int> arr = {2,2,1,1,1,2,2};
    cout<< majorityElmOpt(arr);
    return 0;
}