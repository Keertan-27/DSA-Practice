#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextGreaterElement(vector<int> arr)
{
    vector<int> ans(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

vector<int> nextGreaterElementOptimal(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] >= st.top())
            st.pop();
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {6, 0, 8, 2, 4};
    vector<int> ans = nextGreaterElementOptimal(arr);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}