#include<iostream>
#include<map>
using namespace std;

int NumberOfXORSubarrayBetter(vector<int> a, int K)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int XR = 0;
        for (int j = i; j < a.size(); j++)
        {
            XR = XR ^ a[j];

            if (XR == K)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int NumberOfXORSubarrayOptimal(vector<int> a, int K)
{
    int cnt = 0;
    int preXor = 0;
    map <int, int> mpp;
    mpp[0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
       preXor = preXor ^ a[i];
       int remain = preXor ^ K;
       cnt += mpp[remain];
       mpp[preXor]++;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int ans = NumberOfXORSubarrayBetter(arr, 6);
    cout<< ans;
    return 0;
}