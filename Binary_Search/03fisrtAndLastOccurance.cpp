#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int upperBound(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

pair<int, int> firstLastPosition(vector<int> arr, int x)
{
    int n = arr.size();
    int lb = lowerBound(arr, x);
    if (lb == n || arr[lb] != x)
        return {-1, -1};
    return {lb, upperBound(arr, x) - 1};
}

int fistAppearance(vector <int> arr, int x)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int first = -1;
    while (low<= high)
    {
        int mid = (high + low)/ 2;
        if (arr[mid] == x)
        {
            first = mid;
            high = mid-1;
        }
        else if(arr[mid] > x) high = mid -1;
        else low = mid+1;
    }
    return first;
}

int lastAppearance(vector <int> arr, int x)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int last = -1;
    while (low<= high)
    {
        int mid = (high + low)/ 2;
        if (arr[mid] == x)
        {
            last = mid;
            low = mid+1;
        }
        else if(arr[mid] > x) high = mid -1;
        else low = mid+1;
    }
    return last;
}

int main()
{
    vector<int> arr = {2, 5, 6, 8, 10, 10, 10, 10, 14, 16, 18, 32};
    int target = 10;
    pair<int, int> ans = firstLastPosition(arr, target);
    int first_appearance = fistAppearance(arr, target);
    int last_appearance = lastAppearance(arr, target);
    cout << "First appearance is at: " << ans.first << endl;
    cout << "Second appearance is at: " << ans.second<< endl;
    cout<< "First Appearance: "<< first_appearance << endl;
    cout<< "Last Appearance: "<< last_appearance << endl;

    return 0;
}