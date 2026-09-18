#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intrectionTwoArr(vector<int> nums1, vector<int> nums2)
{
    vector<int> ans;
    unordered_set<int> st;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                st.insert(nums1[i]);
            }
        }
    }
    for (auto x : st)
    {
        ans.push_back(x);
    }

    return ans;
}

vector<int> intersectionTwoArrBetter(vector<int> nums1, vector<int> nums2)
{
    unordered_set<int> st;
    unordered_set<int> st1;
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        st.insert(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        if (st.find(nums2[i]) != st.end())
        {
            st1.insert(nums2[i]);
        }
    }

    for (auto x : st1)
    {
        ans.push_back(x);
    }
    return ans;
}

vector<int> intersectionTwoArrOpt(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            if (ans.empty() || ans.back() != nums1[i])
            {
                ans.push_back(nums1[i]);
            }
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
            i++;
        else
            j++;
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> ans = intersectionTwoArrOpt(nums1, nums2);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}