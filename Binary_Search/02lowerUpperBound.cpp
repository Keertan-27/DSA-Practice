#include<iostream>
#include<vector>
using namespace std;
// if we need to inseart a element or need to find the ceil we should use lower bound 
// can also use the predefined function lower_bound for it
int lowerBound(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if (arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}

int upperBound(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }

    return ans;
}

int floor(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid] <= target){
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }

    return ans;
}

int main()
{
    vector<int> arr = {2,5,6,8,10,14,16,18,32};
    int target = 9;

    int ans = floor(arr, target);
    int ans1 = lowerBound(arr, target);

    cout << "Floor of "<< target << " is at index: " << ans<<endl;
    cout << "Lower bound is at index: " << ans1;

    return 0;
}