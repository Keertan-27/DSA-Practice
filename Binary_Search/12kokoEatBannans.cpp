#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int claculateHourToeat(vector<int> arr, int value)
{
    int TotalH = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        TotalH += ceil((double)arr[i] / (double)value);
    }
    return TotalH;
}
int minTimeToEatBannans(vector<int> arr, int H)
{
    int low = 0, high = findMax(arr);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int TotalH = claculateHourToeat(arr, mid);
        if (TotalH <= H)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    vector<int> pile = {3, 6, 7, 11};
    int hours = 8;
    int ans = minTimeToEatBannans(pile, hours);
    cout<<ans;
    return 0;
}