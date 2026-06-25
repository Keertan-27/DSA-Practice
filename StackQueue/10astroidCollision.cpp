#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> astroidCollision(vector<int> arr)
{
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            st.push(arr[i]);
        }
        else
        {
            while (!st.empty() && st.top() > 0 && st.top() < abs(arr[i]))
            {
                st.pop();
            }
            if (!st.empty() && st.top() > 0 && st.top() == abs(arr[i]))
            {
                st.pop();
            }
            else if (st.empty() || st.top() < 0)
            {
                st.push(arr[i]);
            }
        }
    }

    vector<int> ans(st.size());

    for (int i = st.size() - 1; i >= 0; i--)
    {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}

vector<int> astroidCollisionMoreOptimal(vector<int> arr)
{
    vector<int> stArr;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            stArr.push_back(arr[i]);
        }
        else
        {
            while (!stArr.empty() && stArr.back() > 0 && stArr.back() < abs(arr[i]))
            {
                stArr.pop_back();
            }
            if (!stArr.empty() && stArr.back() > 0 && stArr.back() == abs(arr[i]))
            {
                stArr.pop_back();
            }
            else if(stArr.empty() || stArr.back() < 0)
            {
                stArr.push_back(arr[i]);
            }
        }
    }

    return stArr;
}
int main()
{
    vector<int> arr = {-4, 7, 1, 1, 2, -3, -7, 17, 15, -16};
    vector<int> ans = astroidCollisionMoreOptimal(arr);
    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}