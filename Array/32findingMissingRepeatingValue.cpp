#include <iostream>
#include <vector>
using namespace std;

vector<int> findingMissingRepeatingBrut(vector<int> a)
{
    int missing = -1, repeating = -1;
    for (int i = 1; i <= a.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == i)
            {
                cnt++;
            }
        }
        if (cnt == 0)
            missing = i;
        else if (cnt == 2)
            repeating = i;
        if (missing != -1 && repeating != -1)
        {
            break;
        }
    }
    return {missing, repeating};
}

vector<int> findingMissingRepeatingBetter(vector<int> a)
{
    int missing = -1, repeating = -1;
    int n = a.size();
    vector<int> hasharr(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hasharr[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hasharr[i] == 0)
            missing = i;
        else if (hasharr[i] == 2)
            repeating = i;
        if (missing != -1 && repeating != -1)
        {
            break;
        }
    }

    return {missing, repeating};
}

vector<int> findingMissingRepeatingOptimal(vector<int> a)
{
    int n = a.size();
    long long S = 0, S2 = 0;
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += long(a[i]) * long(a[i]);
    }
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {int(x), int(y)};
}

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> ans = findingMissingRepeatingBetter(arr);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}