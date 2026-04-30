#include <iostream>
#include <vector>
using namespace std;
// All the value int he right should be less than current value
vector<int> leaderInArrayBrut(vector<int> a)
{
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        int leader = true;
        for (int j = i+1; j < a.size(); j++)
        {
            if (a[i] < a[j] )
            {
                leader = false;
                break;
            }
        }
        if (leader == true)
        {
            ans.push_back(a[i]);
        }
    }
    return ans;
}

vector<int> leaderInArrayOptimal(vector<int> a)
{
    vector<int> ans;
    int n  =a.size();
    // int leader = a[n-1];
    int maxValue = INT_MIN;
    for (int i = n-1; i >= 0; i--)
    {
        if (a[i] > maxValue)
        {
            ans.push_back(a[i]);
        }
        maxValue = max(maxValue, a[i]);
    }
    // if need to return in sorted array then the above code is enough but if they want it in the same order as in array then
    //  needs to reverse it
    // reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {4,3,2,1};
    vector<int> arr1 = {10,22,1,9,2,6};
    vector<int> ans = leaderInArrayOptimal(arr);
    vector<int> ans1 = leaderInArrayOptimal(arr1);
    
    for (auto it : ans)
    {
        cout << it<< " ";
    }
    cout<<endl;

    for (auto it : ans1)
    {
        cout << it<< " ";
    }
    return 0;
}