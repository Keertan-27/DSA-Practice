#include <iostream>
#include <vector>
using namespace std;
int subarraySumequalK(vector<int> arr, int K)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        int j = i;
        while (j < arr.size() && sum < K)
        {
            sum += arr[j];
            j++;
        }
        if (sum == K)
        {
            cnt++;
        }
    }
    return cnt;
}

int subarraySumequalKOptimal(vector<int> arr, int K)
{
    int cnt = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        int need = sum - K;
        if (mp.find(need) != mp.end())
        {
            cnt = cnt + mp[need];
        }

        mp[sum]++;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {1, 2, 1, 1, 1, 3};
    int ans = subarraySumequalKOptimal(arr, 3);
    cout << ans;
    return 0;
}