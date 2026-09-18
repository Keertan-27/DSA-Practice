#include<iostream>
#include<vector>
using namespace std;

int maxSumSubarray(vector<int> &nums)
{
    int maxSum = INT_MIN, sum =0;
    for(int x: nums){
        sum += x;
        if(sum<0)
            sum =0;
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {1};
    cout<< maxSumSubarray(arr);
    // for(auto x: arr){
    //     cout<< x<< " ";
    // }
    return 0;
}