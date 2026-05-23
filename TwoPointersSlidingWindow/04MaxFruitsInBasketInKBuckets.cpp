#include<iostream>
#include<vector>
#include<map>
using namespace std;

int maxFruitsInKBuckets(vector<int> arr, int K)
{
    int right = 0, left = 0;
    int maxLen = 0;
    map <int, int> mp;
    while (right<arr.size())
    {
        mp[arr[right]]++;
        while(mp.size()>K)
        {
            mp[arr[left]]--;
            if (mp[arr[left]] == 0)
                mp.erase(arr[left]);
            left++;
        }
        if(mp.size()<=K){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
    int ans = maxFruitsInKBuckets(arr, 2);
    cout<<ans;
    return 0;
}