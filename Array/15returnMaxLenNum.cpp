#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

int returnMaxLenNumBetter(vector<int> a)
{
    int n = a.size();
    map<int, int> mappingArr;
    for (int i = 0; i < n; i++)
    {
        mappingArr[a[i]]++;
    }
    for (auto it : mappingArr)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }
    return -1;
}

int returnMaxLenNumOptimal(vector <int>a)
{
    int cnt =0;
    int element;
    for (int i = 0; i < a.size(); i++)
    {
        if (cnt == 0)
        {
            cnt=1;
            element = a[i];
        }
        if (a[i] == element)
            cnt++;
        else
            cnt--;
    }
    int elmCnt=0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == element)
        {
            elmCnt++;
        }
    }
    if (elmCnt > a.size() / 2)
    {
        return element;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 2, 3, 4, 1, 1};
    int ans = returnMaxLenNumOptimal(arr);
    cout << ans;
    return 0;
}