#include <iostream>
#include <vector>
using namespace std;

int maxPointsFromCards(vector<int> arr, int K)
{
    int n = arr.size();
    int maxSum = 0;
    int lsum = 0, rsum = 0;
    for (int i = 0; i < K; i++)
        lsum += arr[i];
    maxSum = lsum;
    int rIndex = n - 1;
    for (int i = K - 1; i >= 0; i--)
    {
        lsum = lsum - arr[i];
        rsum = rsum + arr[rIndex];
        rIndex--;
        maxSum = max(maxSum, lsum + rsum);
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int K = 4;
    int ans = maxPointsFromCards(arr, K);
    cout << ans;
    return 0;
}