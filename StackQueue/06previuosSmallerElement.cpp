#include<iostream>
#include<vector>
using namespace std;

vector<int> previousSmallerElm(vector<int> arr)
{
    stack <int> st;
    vector<int> ans(arr.size(), -1);
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && st.top() >= arr[i])
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
    vector<int> arr ={4,5,2,10,8};
    vector<int> ans = previousSmallerElm(arr);

    for (int x : ans)
    {
        cout<< x<< " ";
    }
    return 0;
}