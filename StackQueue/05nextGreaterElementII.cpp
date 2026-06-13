#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < 2*n-1; j++)
        {
            int idx = j % n;
            if (arr[idx] > arr[i])
            {
                ans[i] = arr[idx];
                break;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 6, 0, 8, 2, 4, 3};
    vector<int> ans = nextGreaterElement(arr);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}