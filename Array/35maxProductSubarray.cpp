#include<iostream>
#include<vector>
using namespace std;

int maxProductSubarray(vector<int> arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        int prod = 1;
        for (int j = i; j < arr.size(); j++)
        {
            prod *= arr[j];
            maxi = max(maxi, prod);
        }
    }
    return maxi;
}

int maxProductSubarrayOptimal(vector<int> &arr)
{
    int maxi = INT_MIN;
    int pre = 1, suff = 1;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;

        pre *= arr[i];
        suff *= arr[n-i-1];
        maxi = max(maxi, max(pre,suff));
    }
    return maxi;
}

int main()
{
    vector<int> arr = {2,8,-2,4,0,9};
    int ans = maxProductSubarrayOptimal(arr);
    cout<<ans;
    return 0;
}