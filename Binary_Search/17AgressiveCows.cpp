#include <iostream>
#include <vector>
using namespace std;
int agressiveCows(vector<int> arr, int cows)
{
    sort(arr.begin(), arr.end());

    int mini = arr[0];
    int maxi = arr[arr.size() - 1];

    int low = 1, high = maxi - mini;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int last = arr[0];
        int cntCow = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - last >= mid)
            {
                cntCow++;
                last = arr[i];
            }
        }

        if (cntCow >= cows)
        {
            low = mid + 1
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
int main()
{
    vector<int> arr = {0, 3, 4, 7, 9, 10};
    int cows = 4;
    int ans = agressiveCows(arr, cows);
    cout << ans;
    return 0;
}