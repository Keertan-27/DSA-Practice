#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> nextGreaterElemnt(vector<int> arr1, vector<int> arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> ans(n1);
    stack<int> st;
    unordered_map<int, int> mpNge;
    for (int i = n2 - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr2[i])
            st.pop();
        mpNge[arr2[i]] = st.empty() ? -1 : st.top();

        st.push(arr2[i]);
    }

    for (int i = 0; i < n1; i++)
    {
        ans[i] = mpNge[arr1[i]];
    }
    return ans;
}
int main()
{
    vector<int> arr1 = {4, 1, 2};
    vector<int> arr2 = {1, 3, 4, 2};
    vector<int> ans = nextGreaterElemnt(arr1, arr2);
    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}