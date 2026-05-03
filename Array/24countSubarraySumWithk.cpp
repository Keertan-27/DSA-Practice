#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// better solution
int longestsubarrayWithSumKbetter(vector<int> &arr, int Ksum)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == Ksum)
            {
                cnt++;
            }
        }
    }
    return cnt;    
}

// optimal solution
int longestsubarrayWithSumKOptimal(vector<int> &arr, int Ksum)
{
    unordered_map <int, int> mpp;
    mpp[0] =1;
    int cnt = 0;
    int preSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        int remove = preSum - Ksum;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    
    return cnt;    
}

int main()
{
    int n = 10;
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    int ans = longestsubarrayWithSumKOptimal(arr, 3);
    cout << ans;
    return 0;
}