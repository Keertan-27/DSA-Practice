#include <iostream>
#include <vector>
#include <map>
using namespace std;
// worst solution O(n3)
int longestsubarrayWithSumKWorst(vector<int> &arr, int Ksum)
{
    int len = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == Ksum)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

// brut force
int longestsubarrayWithSumKBrut(vector<int> &arr, int Ksum)
{
    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            sum += arr[j];

            if (sum == Ksum)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

// better hash map
int longestsubarrayWithSumKBetter(vector<int> &arr, long long Ksum)
{
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == Ksum)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long rem = sum - Ksum;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

// best optimal solution
int longestsubarrayWithSumKOptimal(vector<int> &arr, int Ksum)
{
    int sum = 0;
    int maxLen = 0;
    int i = 0, j = 0;
    while (i < arr.size())
    {
        sum += arr[i];

        while (sum > Ksum && j <= i)
        {
            sum -= arr[j];
            j++;
        }

        if (sum == Ksum)
        {
            maxLen = max(maxLen, i - j + 1);
        }

        i++;
    }

    return maxLen;
}

int main()
{
    int n = 10;
    vector<int> arr = {1, 2, 0, 3, 4, 0, 5, 0, 1, 1, 1};
    int k = 3;
    int ans = longestsubarrayWithSumKOptimal(arr, 3);
    cout << ans;
    return 0;
}