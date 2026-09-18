#include <iostream>
#include <vector>
using namespace std;
vector<int> rotateArrayL(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> temp;
    for (int i = n - k; i < n; i++)
    {
        temp.push_back(nums[i]);
    }
    for (int i = 0; i < n - k; i++)
    {
        temp.push_back(nums[i]);
    }
    return temp;
}

void rotateArray(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
int main()
{
    vector<int> arr = {3, 5, 99, 101, 67, 1, 55};
    // left move
    rotateArray(arr, 3);
    // vector<int> ansR = rotateArrayL(arr, 3);
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}