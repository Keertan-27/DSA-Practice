#include <iostream>
#include <vector>
using namespace std;

int longestsubarrayWithSumK(vector<int> &arr, int Ksum)
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

int main()
{
    int n = 10;
    vector<int> arr = {1, 2, 0, 3, 4, 0, 5, 1, 1, 1};
    int k = 3;
    int ans = longestsubarrayWithSumK(arr, 3);
    cout << ans;
    return 0;
}