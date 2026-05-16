#include <iostream>
#include <vector>
using namespace std;
int singleArraySorted(vector<int> arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            return arr[mid];
        if ((arr[mid] % 2 == 1 && arr[mid] == arr[mid - 1]) ||
            arr[mid] % 2 == 0 && arr[mid] == arr[mid + 1])
        {
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6};
    int ans = singleArraySorted(arr);
    cout<<ans;
    return 0;
}