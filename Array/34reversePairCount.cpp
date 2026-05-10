#include<iostream>
#include<vector>
using namespace std;


int reversePairBrut(vector<int> arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] > 2 * arr[j])
                cnt++;
        }
    }
    return cnt;
}

// second approach optimal is using the merge sort logic
void mergefun(vector<int>& arr, int low, int mid, int high)
{
    int cnt = 0;
    int left = low, right=mid+1;
    vector<int> temp;
    while (left<=mid && right<=high)
    {
        if (arr[right]<arr[left])
        {
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
}

int countPairs(vector<int> arr, int low, int mid, int high)
{
    int right = mid +1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right<= high && arr[i] > 2*arr[right]) right++;
        cnt += (right - (mid+1));
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
    cnt += countPairs(arr, low, mid, high);
    mergefun(arr, low, mid, high);
    return cnt;
}

int mergeSortReversePair(vector<int> &arr, int n)
{
    return mS(arr, 0, n-1);
}

int main()
{
    vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
    
    int brutAns = reversePairBrut(arr, 7);
    int mergeAns = mergeSortReversePair(arr, 7);
    
    cout << "Brute Force: " << brutAns << endl;
    cout << "Merge Sort: " << mergeAns << endl;
    
    return 0;
}