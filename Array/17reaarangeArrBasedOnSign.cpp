#include <iostream>
#include <vector>
using namespace std;

vector<int> reaaragneBasedOnSignBrut(vector<int> a)
{
    int n = a.size();
    vector<int> tempPos, tempNeg;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            tempPos.push_back(a[i]);
        }
        if (a[i] <0)
        {
            tempNeg.push_back(a[i]);
        }
    }

    for (int i = 0; i < n/2; i++)
    {
        a[2*i] = tempPos[i];
        a[2*i+1] = tempNeg[i];
    }
    return a;
}

vector<int> reaaragneBasedOnSignOptimal(vector<int> a)
{
    vector<int> ans(a.size(),0);
    int posIndex =0, negIndex =1;

    for (int i = 0; i < a.size(); i++)
    {
        if(a[i]>0)
        {
            ans[posIndex] = a[i];
            posIndex += 2;
        }
        else{
            ans[negIndex] = a[i];
            negIndex +=2;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 5, -3, 4, -1, -2};
    vector<int> ans =reaaragneBasedOnSignOptimal(arr);
    for(auto it: ans)
    {
        cout<< it<< " ";
    }
    return 0;
}