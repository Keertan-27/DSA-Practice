#include <iostream>
#include <vector>
using namespace std;

int calNoOfBouquet(int mid, int k, vector<int> arr)
{
    int noOfB = 0;
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (mid >= arr[i])
        {
            cnt++;
        }
        else
        {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB;
}
int minNoOfDaysMakeMBouquet(vector<int> arr, int m, int k)
{
    int n = arr.size();
    if (m * k > n)
        return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (calNoOfBouquet(mid, k, arr) >= m)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int noOfBouqetReq = 2;
    int adjacantFlow = 3;
    int ans = minNoOfDaysMakeMBouquet(arr, noOfBouqetReq, adjacantFlow);
    cout << ans;
}