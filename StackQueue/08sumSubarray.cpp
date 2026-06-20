#include<iostream>
#include<stack>
using namespace std;

int minSumAllSubarrayBrut(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int minVal = arr[i];
        for (int j = i; j < arr.size(); j++)
        {
            minVal = min(minVal, arr[j]);
            sum += minVal;
        }
    }
    return sum;
}

int minSumAllSubarrayOptimal(vector<int> arr)
{
    int sum = 0;
    return sum;
}
int main()
{
    vector<int> arr = {3,1,2,4};
    int ans = minSumAllSubarrayBrut(arr);
    cout<<ans;
    return 0;
}