#include <iostream>
#include <vector>
using namespace std;

int NumTimesArrayRoated(vector<int> arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int minVal = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] < arr[high])
        {
            if (arr[low] < minVal)
            {
                index = low;
                minVal = min(minVal, arr[low]);
            }
            break;
        }

        if (arr[low] <= arr[mid])
        {
            if(arr[low]< minVal){
                minVal = min(minVal, arr[low]);
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if(arr[mid]< minVal){
                
                minVal = min(minVal, arr[mid]);
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int ans = NumTimesArrayRoated(arr);
    cout << ans;
    return 0;
}