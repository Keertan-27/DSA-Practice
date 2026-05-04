#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> fourSumBrut(vector<int> a, int target)
{
    set<vector<int>> st;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = (a[i] + a[j]);
                    sum += a[k];
                    sum += a[l];
                    if (sum == target)
                    {
                        vector<int> temp = {a[i], a[j], a[k], a[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSumBetter(vector<int> a, int target)
{
    set<vector<int>> st;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> hashset;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = (a[i] + a[j]);
                sum += a[k];
                long long fourth = target - sum;

                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {a[i], a[j], a[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(a[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSumOptimal(vector<int> a, int target)
{
    sort(a.begin(), a.end());
    int n = a.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && a[j] == a[j - 1])
                continue;
            int k = j + 1, l = n - 1;
            while (k < l)
            {
                long long sum = a[i] + a[j];
                sum += a[k];
                sum += a[l];
                if (sum < target)
                    k++;
                else if (sum > target)
                    l--;
                else
                {
                    vector<int> temp = {a[i], a[j], a[k], a[l]};
                    ans.push_back(temp);
                    k++, l--;
                    while (k < l && a[k] == a[k - 1])
                        k++;
                    while (k < l && a[l] == a[l + 1])
                        l--;
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -2, -1, 0};
    int target = 1;
    vector<vector<int>> ans = fourSumBetter(arr, target);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}