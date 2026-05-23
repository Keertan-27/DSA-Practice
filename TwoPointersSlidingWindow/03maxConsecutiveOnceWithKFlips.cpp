#include<iostream>
#include<vector>
using namespace std;
// Time Complexity = O(2N)
int maxConsecutiveLenBetter(vector<int> arr, int K){
    int right = 0, left = 0;
    int maxLen = 0;
    int zeroCnt = 0; 
    while (right<arr.size())
    {
        if (arr[right] == 0)
            zeroCnt++;
        while (zeroCnt > K)
        {
            if (arr[left] == 0)
                zeroCnt--;

            left++;
        }
        if(zeroCnt<=K){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }
    return maxLen;
}
// Time Complexity O(N)
int maxConsecutiveLenOptimal(vector<int> arr, int K){
    int right = 0, left = 0;
    int maxLen = 0;
    int zeroCnt = 0; 
    while (right<arr.size())
    {
        if (arr[right] == 0)
            zeroCnt++;
        if (zeroCnt > K)
        {
            if (arr[left] == 0)
                zeroCnt--;

            left++;
        }
        if(zeroCnt<=K){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    vector<int> arr1 = {1};
    int ans = maxConsecutiveLenBetter(arr, 2);
    int ans1 = maxConsecutiveLenOptimal(arr, 2);

    cout<<ans<<endl;
    cout<<ans1;
    return 0;
}