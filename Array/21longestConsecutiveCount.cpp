#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutiveCountBrut(vector<int> a)
{
    int maxLongest = 1;
    for (int i = 0; i < a.size(); i++)
    {
        int x = a[i];
        int longest = 1;
        for (int k = 0; k < a.size(); k++)
        {
            bool found = false;
            for (int j = 0; j < a.size(); j++)
            {
                if (a[j] == x + 1)
                {
                    longest++;
                    x++;
                    found = true;
                    break;
                }
            }
            if (!found)
                break;
        }
        maxLongest = max(longest, maxLongest);
    }
    return maxLongest;
}

int longestConsecutiveCountBetter(vector<int> a)
{
    sort(a.begin(), a.end());
    int longest = 1, currCount = 0, lastSmall = INT_MIN;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] - 1 == lastSmall)
        {
            currCount++;
            lastSmall = a[i];
        }
        else if (a[i] != lastSmall)
        {
            currCount = 1;
            lastSmall = a[i];
        }

        longest = max(longest, currCount);
    }
    return longest;
}

int longestConsecutiveCountOptimal(vector<int> a)
{
    unordered_set<int> st;
    int longest = 1;
    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    } 
    return longest;
}

    int main()
    {
        vector<int> arr = {4, 3, 2, 1};
        vector<int> arr1 = {100, 102, 100, 101, 103, 1, 1, 4, 4, 2, 2, 3};
        int ans = longestConsecutiveCountOptimal(arr);
        int ans1 = longestConsecutiveCountOptimal(arr1);
        cout << ans;
        cout << endl;
        cout << ans1;
        return 0;
    }