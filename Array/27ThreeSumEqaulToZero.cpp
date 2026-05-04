#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> threeSumBrut(vector<int> a)
{
    set<vector<int>> st;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            for (int k = j + 1; k < a.size(); k++)
            {
                if (a[i] + a[j] + a[k] == 0)
                {
                    vector<int> temp = {a[i], a[j], a[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

vector<vector<int>> threeSumBetter(vector<int> a)
{
    set<vector<int>> st;
    for (int i = 0; i < a.size(); i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < a.size(); j++)
        {
            int third = -(a[i] + a[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {a[i], a[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(a[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSumOptimal(vector<int> a)
{
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && a[i] == a[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = (a[i] + a[j] + a[k]);
            if (sum < 0)
                j++;
            if (sum > 0)
                k--;
            else
            {
                vector<int> temp = {a[i], a[j], a[k]};
                ans.push_back(temp);
                j++, k--;
                while (j < k && a[j] == a[j - 1])
                    j++;
                while (j < k && a[k] == a[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<int> arr1 = {-2, 1, -1, -2, -2, -1, 0, 0, 0, 2, 2, 2, 2};
    vector<vector<int>> ans = threeSumBetter(arr);
    vector<vector<int>> ans1 = threeSumBetter(arr1);

    for (int i = 0; i < ans1.size(); i++)
    {
        for (int j = 0; j < ans1[i].size(); j++)
        {
            cout << ans1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}