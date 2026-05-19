#include<iostream>
#include<vector>
using namespace std;
int KthMissingNum(vector<int> arr, int K)
{
    int n = arr.size();
    int low = 0, high = n-1;
    while (low<=high)
    {
        int mid =(low+high)/2;
        int missing = arr[mid] - (mid + 1);
        if(missing<K){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return K+low; // K+ high +1
    
}
int main()
{
    vector<int> arr = {2,3,4,7,11};
    int K = 5;
    int ans = KthMissingNum(arr,K);
    cout<<ans;
    return 0;
}
