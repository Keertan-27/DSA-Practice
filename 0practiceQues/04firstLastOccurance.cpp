#include<iostream>
#include<vector>
using namespace std;

int firstOccurance(vector<int> nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low+high)/2;
       
        if (nums[mid] >= target)
        {
            high = mid - 1;
        }else{
            low = mid +1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {5,7,7,8,8,10};
    int target = 8;
    return 0;
}