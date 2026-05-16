#include<iostream>
#include<vector>
using namespace std;

int miniValueRotatedArray(vector<int> arr)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int minValue = INT_MAX;

    while (low<=high)
    {
        int mid = (low+high) /2;
        if(arr[low] <= arr[mid])
        {
            minValue = min(minValue, arr[low]);
            low = mid+1;
        }
        else{
            high = mid -1;
            minValue = min(minValue, arr[mid]);
        }
    }
    return minValue;
}

int main()
{
    vector<int> arr = {7,8,9,1,2,3,4,5,6};
    int ans = miniValueRotatedArray(arr);
    cout<< ans;
}