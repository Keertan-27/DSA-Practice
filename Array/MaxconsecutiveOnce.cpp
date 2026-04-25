#include <iostream>
#include <vector>
using namespace std;

int maxConsecutiveOnce(vector<int> a)
{
    int n = a.size();
    int max = 0;
    int cons = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            cons += 1;
            if (max < cons)
            {
                max = cons;
            }
        }
        else
        {
            cons = 0;
        }
    }

    return max;
}
int main()
{
    vector<int> a = {0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1};
    int ans = maxConsecutiveOnce(a);
    cout << ans << " ";
    return 0;
}