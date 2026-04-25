#include<iostream>
using namespace std;

//better solution
int valueAppOnceOnlyBetter(vector <int> a)
{
    
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
    vector <int> arr = {1,1,2,2,3,4,4,8,8};


    int ans = valueAppearingOnceOnly(arr);
    cout<< ans;

    return 0;
}