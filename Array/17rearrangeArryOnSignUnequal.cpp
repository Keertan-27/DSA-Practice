#include <iostream>
#include <vector>
using namespace std;
// Numb of positive and negative are not equal
vector<int> reaaragneBasedOnSignUnequalPosNeg(vector<int> a)
{
    int n = a.size();
    vector<int> tempPos, tempNeg;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            tempPos.push_back(a[i]);
        }
        if (a[i] < 0)
        {
            tempNeg.push_back(a[i]);
        }
    }

    if (tempPos.size() > tempNeg.size())
    {
        for (int i = 0; i < tempNeg.size(); i++)
        {
            a[2 * i] = tempPos[i];
            a[2 * i + 1] = tempNeg[i];
        }
        int idx = 2 * tempNeg.size();
        for (int i = tempNeg.size(); i < tempPos.size(); i++)
        {
            a[idx] = tempPos[i];
            idx++;
        }
    }
    else
    {
        for (int i = 0; i < tempPos.size(); i++)
        {
            a[2 * i] = tempPos[i];
            a[2 * i + 1] = tempNeg[i];
        }
        int idx = 2 * tempPos.size();
        for (int i = tempPos.size(); i < tempNeg.size(); i++)
        {
            a[idx++] = tempNeg[i];
        }
    }
    return a;
}

int main()
{
    vector<int> arr = {2, 5, -3, 4, -1, 8, -2, 3, 6};
    vector<int> ans = reaaragneBasedOnSignUnequalPosNeg(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}