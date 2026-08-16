#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

vector<vector<int>> threeSumBrut(vector<int> arr)
{
    int n = arr.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSumBetter(vector<int> arr)
{
    set<vector<int>> st;
    for (int i = 0; i < arr.size(); i++)
    {
        unordered_set<int> hashSet;
        for (int j = i + 1; j < arr.size(); j++)
        {
            int remain = -(arr[i] + arr[j]);
            if (hashSet.find(remain) != hashSet.end())
            {
                vector<int> temp = {arr[i], arr[j], remain};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSumOptimal(vector<int> arr)
{
    sort(arr.begin() , arr.end());
    int n = arr.size();
    vector<vector<int>>ans;
    for (int i = 0; i < n-2; i++)
    {
        if(i>0 && arr[i] == arr[i-1])
            continue;
        int l = i+1;
        int r = n-1;

        while (l<r)
        {
            int sum = arr[i] + arr[r] + arr[l];
            if (sum<0) l++;
            else if(sum>0) r--;
            else{
                ans.push_back({arr[i], arr[l], arr[r]});
                l++, r--;
                while (l<r && arr[l] == arr[l-1])
                    l++;
                while(l<r && arr[r] == arr[r+1])
                    r--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSumOptimal(arr);
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