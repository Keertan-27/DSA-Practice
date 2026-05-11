#include<iostream>
#include<vector>
using namespace std;

bool basicBinarySearch(vector<int> arr, int target)
{
    int n = arr.size();
    int low = arr[0];
    int high= arr[n-1];
    while (low<=high)
    {
        int mid = (low + high)/2;

        if (arr[mid] == target) return 1;
        else if (arr[mid] < target) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int BS(vector<int> &arr, int low, int high, int target)
{
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(arr[mid] == target) return mid;
    else if(arr[mid]>target) return BS(arr, low, mid-1, target);
    else return BS(arr, mid+1, high, target);
}
int basicBinarySearchRecursion(vector<int> &arr, int target)
{
    int n = arr.size();
    return BS(arr, 0, n-1, target);
}

int main()
{
    vector<int> arr = {2,5,6,8,10,14,16,18,32};
    int target = 10;
    int ans = basicBinarySearchRecursion(arr, target);
    if(ans != -1)
        cout << "Element found at index: " << ans;
    else
        cout << "Element not found: "<< ans;
    return 0;
}