#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int largestRectangleInHistogram(vector<int> arr)
{
    int n = arr.size();
    vector<int> pse(n),nse(n);
    stack<int> st1, st2;
    // pse logic
    for (int i = 0; i < n; i++)
    {
        while (!st1.empty() && arr[st1.top()] >= arr[i])
            st1.pop();

        if (st1.empty())
            pse[i] = -1;
        else
            pse[i] = st1.top();
        
        st1.push(i);
    }
    
    // nse logic
    for (int i = n-1; i >= 0; i--)
    {
        while (!st2.empty() && arr[st2.top()] >= arr[i])
            st2.pop();

        if (st2.empty())
            nse[i] = n;
        else
            nse[i] = st2.top();
            
        st2.push(i);
    }
    
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i] * (nse[i] - pse[i] - 1));
    }
    return maxi;
}

int main()
{
    vector<int> arr = {2,4};
    int ans = largestRectangleInHistogram(arr);
    cout<<ans;
    return 0;
}