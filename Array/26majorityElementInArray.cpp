#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;
// We need to find a elemnt which appears more than n/3 times in an array
// at max 2 elements can be present in an array with more than n/3 times
list<int> majorityElementInArray(vector<int> a)
{
    list<int> ls;
    map<int, int> mpp;
    int n = a.size();
    int min = int(n / 3) + 1;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]]++;
        if (mpp[a[i]] == min)
        {
            ls.push_back(a[i]);
        }
        if (ls.size() == 2)
        {
            break;
        }
    }
    return ls;
}
vector<int> majorityElementInArrayOptimal(vector<int> a)
{
    int cnt1 = 0, cnt2 = 0;
    int elm1 = INT_MIN;
    int elm2 = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        if (cnt1 == 0 && elm2 != a[i])
        {
            cnt1 = 1;
            elm1 = a[i];
        }
        else if (cnt2 == 0 && elm1 != a[i])
        {
            cnt2 = 1;
            elm2 = a[i];
        }
        else if (a[i] == elm1)
            cnt1++;
        else if (a[i] == elm2)
            cnt2++;
        else
            cnt1--, cnt2--;
    }
    
    vector<int> ls;
    cnt1 = 0, cnt2 =0;
    for (int i = 0; i < a.size(); i++)
    {
        if (elm1 == a[i]) cnt1++;
        if (elm2 == a[i]) cnt2++;        
    }
    int mini = int(a.size()/3) + 1;
    if (cnt1 >= mini) ls.push_back(elm1);
    if (cnt2 >= mini) ls.push_back(elm2);
    
    return ls;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3, 3};
    vector<int> ans = majorityElementInArrayOptimal(arr);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}