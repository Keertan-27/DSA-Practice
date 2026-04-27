#include<iostream>
using namespace std;

//better solution
int valueAppOnceOnlyBetter(vector <int> a)
{
    int N = 0;
    for (int i = 0; i < a.size(); i++)
    {
        N = max(N , a[i]);
    }

    vector <int> hashh(N+1,0);
    for (int i = 0; i < a.size(); i++)
    {
            hashh[a[i]]++;
    }
    for (int i = 0; i <= N; i++)
    {
        if (hashh[i] == 1)
        {
            return i;
        }
        
    }
    return -1;
}

// optimal solution
int valueAppearingOnceOnly(vector<int> a)
{
    int XOR = 0;

    for(int i =0; i<a.size(); i++)
    {
        XOR = XOR ^ a[i];
    }
    return XOR;
}

int main()
{
    vector <int> arr = {1,1,2,2,3,3,4,4,8,8,9};
    int ansBetter = valueAppOnceOnlyBetter(arr);
    cout<< ansBetter << endl;

    int ans = valueAppearingOnceOnly(arr);
    cout<< ans<< endl;

    return 0;
}