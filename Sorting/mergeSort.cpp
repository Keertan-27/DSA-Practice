#include<iostream>
#include<vector>
using namespace std;

void mergeFun(vector<int> &arr, int low, int mid,int high)
{
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while (left<= mid && right<= high)
    {
        if (arr[left] <arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
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
void mS(vector<int> &arr, int low, int high)
{
    if (low >= high) return;
    int mid = (low+high)/2;
    mS(arr, low, mid);
    mS(arr, mid+1, high);
    mergeFun(arr, low, mid, high);
}
vector<int> mergeSort(vector<int> &arr, int n)
{
    mS(arr, 0, n-1);
    return arr;
}
int main()
{
    vector<int> arr = {2,4,1,5,6,7,10,8,1,3,9};
    vector<int> ans = mergeSort(arr, arr.size());
    for (auto it: ans)
    {
        cout<< it<< " ";
    }
    
    return 0;
}