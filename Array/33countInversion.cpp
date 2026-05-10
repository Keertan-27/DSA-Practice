#include<iostream>
#include<vector>
using namespace std;


int countInversionBrut(vector<int> arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    return cnt;
}

// second approach optimal is using the merge sort logic
int mergefun(vector<int>& arr, int low, int mid, int high)
{
    int cnt = 0;
    int left = low, right=mid+1;
    vector<int> temp;
    while (left<=mid && right<=high)
    {
        if (arr[right]<arr[left])
        {
            cnt += (mid - left + 1);
            temp.push_back(arr[right]);
            right++;
        }
        else
        {
            temp.push_back(arr[left]);
            left++;
        }
    }
    while (left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
    return cnt;
}

int mS(vector<int>& arr, int low, int high)
{
    int cnt = 0;
    if(low == high) return cnt;
    int mid = (high+low)/2;
    cnt += mS(arr,low,mid);
    cnt += mS(arr,mid+1,high);
    cnt += mergefun(arr, low, mid, high);
    return cnt;
}

int mergeSortCountInversion(vector<int> &arr, int n)
{
    return mS(arr, 0, n-1);
}

int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};
    vector<int> arr2 = {5, 3, 2, 4, 1};
    
    int brutAns = countInversionBrut(arr, 5);
    int mergeAns = mergeSortCountInversion(arr2, 5);
    
    cout << "Brute Force: " << brutAns << endl;
    cout << "Merge Sort: " << mergeAns << endl;
    
    return 0;
}