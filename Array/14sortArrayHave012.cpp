#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<int> sortArrayHavezerosoncetwosBetter(vector<int> a)
{
    int n = a.size();
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            count0++;
        else if (a[i] == 1)
            count1++;
        else
            count2++;
    }
    for (int i = 0; i < count0; i++)
        a[i] = 0;
    for (int i = count0; i < count0 + count1; i++)
        a[i] = 1;
    for (int i = count0 + count1; i < n; i++)
        a[i] = 2;

    return a;
}

// Deutch National Flag Algorithm

// 0000000      1111111       ........      2222222
// ^     ^      ^     ^       ^      ^      ^     ^
// |     |      |     |       |      |      |     |
// 0   low-1   low  mid-1    mid   high  high+1  n-1

vector<int> sortArrayHavezerosoncetwosoptimal(vector<int> a)
{
    int n = a.size();
    int low = 0, mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[mid], a[low]);
            low++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else if (a[mid] == 2)
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
    return a;
}
int main()
{
    vector<int> arr = {0, 1, 0, 1, 2, 1, 2, 1, 2, 0, 1, 2};

    vector<int> ans = sortArrayHavezerosoncetwosoptimal(arr);
    for (int it : ans)
    {
        cout << it;
    }

    return 0;
}