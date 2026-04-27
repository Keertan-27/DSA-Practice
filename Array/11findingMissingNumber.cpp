#include <iostream>
#include <vector>
using namespace std;

int findingMissingValueBrut(vector<int> a)
{
    int n = a.size();
    int ans = -1;
    int flag = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int findingMissingValueBetter(vector<int> a)
{
    int n = a.size();
    vector<int> hash(n+2, 0);

    for (int i = 0; i < n; i++)
    {
        hash[a[i]] = 1;
    }
    for (int i = 1; i<=n; i++)
    {
        if (hash[i] == 0)
            return i;
    }
    return -1;
}

int findingMissingValueOptimal(vector<int> a)
{
    int n = a.size();
    int sum=0;
    int sumN = ((n+1)*(n+2))/2;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sumN-sum;
}
int main()
{
    vector<int> a = {1, 2, 3, 5, 6, 7};
    int ans = findingMissingValueOptimal(a);
    cout << ans<< " ";
    return 0;
}