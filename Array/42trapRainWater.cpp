#include<iostream>
#include<vector>
using namespace std;

int trapRainWater(vector<int> arr)
{
    int n = arr.size();
    int total = 0;
    vector<int> preMax(n,0);
    vector<int> sufMax(n,0);
    int lmax = 0; 
    int rmax = 0;
    for (int i = 0; i < n; i++)
    {
        lmax = max(lmax, arr[i]);
        preMax[i] = lmax;
    }
    for (int i = n-1; i >=0; i--)
    {
        rmax = max(rmax, arr[i]);
        sufMax[i] = rmax;
    }

    for (int i = 0; i < n; i++)
    {
        total += (min(preMax[i], sufMax[i]) - arr[i]);
    }
    return total;    
}

int trapRainWateBetter(vector<int> arr)
{
    int n = arr.size();
    int total = 0;
    vector<int> sufMax(n,0);
    int rmax = 0;
    int lmax = 0;
    for (int i = n-1; i >=0; i--)
    {
        rmax = max(rmax, arr[i]);
        sufMax[i] = rmax;
    }

    for (int i = 0; i < n; i++)
    {
        lmax = max(lmax, arr[i]);
        total += (min(lmax, sufMax[i]) - arr[i]);
    }
    return total;    
}
int main()
{
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = trapRainWater(arr);
    cout<<ans;
    return 0;
}