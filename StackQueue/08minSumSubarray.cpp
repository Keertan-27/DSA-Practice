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

long long minSumAllSubarrayOptimal(vector<int> arr)
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
int main()
{
    vector<int> arr = {3,1,2,4,2,5};
    int ans = minSumAllSubarrayBrut(arr);
    cout<<ans<<endl;

    long long sum = minSumAllSubarrayOptimal(arr);
    cout<< sum;
    return 0;
}