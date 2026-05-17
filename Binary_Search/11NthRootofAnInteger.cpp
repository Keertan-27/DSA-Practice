#include<iostream>
using namespace std;

int funcRoot(int n, int m, int mid)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= mid;
        if(ans>m) return 2; 
    }
    if(ans == m) return 1;
    else return 0;
    
}
int NthRootofanInteger(int n, int m)
{
    int low = 0, high = m;
    while (low<=high)
    {
        int mid = (low+high) /2;
        int midN = funcRoot(n,m,mid);
        if(midN == 1) return mid;
        else if (midN == 0)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int main()
{
    int integer = 64;
    int root = 3;
    int ans = NthRootofanInteger(root, integer);
    cout<<ans;
    return 0;
}
