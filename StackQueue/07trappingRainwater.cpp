#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trappingRaingwater(vector<int> arr)
{
    int n = arr.size();
    int total =0;
    vector<int> preMax(n);
    preMax[0] = arr[0]; 
    for (int i = 1; i < n; i++)
    {
        preMax[i] = max(arr[i] , preMax[i-1]);
    }

    vector<int> sufMax(n);
    sufMax[n-1] = arr[n-1]; 
    for (int i = n-2; i >= 0; i--)
    {
        sufMax[i] = max(arr[i] , sufMax[i+1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < preMax[i] && arr[i] < sufMax[i])
        {
            total += min(preMax[i], sufMax[i]) - arr[i];
        }
    }

    return total;
}
int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans= trappingRaingwater(arr);
    cout<<ans;
    return 0;
}