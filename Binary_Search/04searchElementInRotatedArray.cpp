#include <iostream>
#include <vector>
using namespace std;

int searchElementRotatedArray(vector<int> arr, int x)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= x && x <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] <= x && x <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target = 1;
    int ans = searchElementRotatedArray(arr, target);
    cout << ans;
    return 0;
}