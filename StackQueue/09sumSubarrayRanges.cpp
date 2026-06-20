#include<iostream>
#include<stack>
using namespace std;

long long minSumAllSubarray(vector<int> &arr)
{
    long long sum = 0;
    int n = arr.size();
    vector<int> nse(n), pse;
    stack <int> st1, st2;
    // next smaller element for this
    for (int i = n-1; i >= 0; i--)
    {
        while (!st1.empty() && arr[i] <= arr[st1.top()])
            st1.pop();
        
        if (st1.empty())
            nse[i] = n;
        
        else
            nse[i] = st1.top();
        
        st1.push(i);
    }

    // previous samller element
    for (int i = 0; i < n; i++)
    {
        while (!st2.empty() && arr[i] < arr[st2.top()])
            st2.pop();
        
        if (st2.empty())
            pse.push_back(-1);
        
        else
            pse.push_back(st2.top());
        
        st2.push(i);
    }
    
    for (int i = 0; i < n; i++)
    {
        int left = nse[i] - i;
        int right = i - pse[i];

        sum += left * right * 1LL * arr[i];
    }
    
    return sum;
}

long long maxSumAllSubarray(vector<int> &arr)
{
    long long sum = 0;
    int n = arr.size();
    vector<int> nse(n), pse;
    stack <int> st1, st2;
    // next greater element for this
    for (int i = n-1; i >= 0; i--)
    {
        while (!st1.empty() && arr[i] >= arr[st1.top()])
            st1.pop();
        
        if (st1.empty())
            nse[i] = n;
        
        else
            nse[i] = st1.top();
        
        st1.push(i);
    }

    // previous greater element
    for (int i = 0; i < n; i++)
    {
        while (!st2.empty() && arr[i] > arr[st2.top()])
            st2.pop();
        
        if (st2.empty())
            pse.push_back(-1);
        
        else
            pse.push_back(st2.top());
        
        st2.push(i);
    }
    
    for (int i = 0; i < n; i++)
    {
        int left = nse[i] - i;
        int right = i - pse[i];

        sum += left * right * 1LL * arr[i];
    }
    
    return sum;
}

int subarrayRangeSum(vector<int> &arr)
{
    int total = 0;
    total += maxSumAllSubarray(arr) - minSumAllSubarray(arr);
    return total;
}
int main()
{
    vector<int> arr = {1,4,3,2};
    int total = subarrayRangeSum(arr);
    cout<<total;
}