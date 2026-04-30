#include <iostream>
#include <vector>
using namespace std;
// Buy and sell stock for max profit (we can only sell after buying the stock)
vector<int> nextPermutationArray(vector<int> a)
{
    int index = -1;
    int n = a.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(a.begin(), a.end());
        return a;
    }

    for (int i = n - 1; i > index; i--)
    {
        if (a[i] > a[index])
        {
            swap(a[i], a[index]);
            break;
        }
    }

    reverse(a.begin() + index + 1, a.end());

    return a;
}

int main()
{
    vector<int> arr = {4,3,2,1};
    vector<int> arr1 = {2,3,5,4,1,0,0};

    vector<int> ans = nextPermutationArray(arr);
    vector<int> ans1 = nextPermutationArray(arr1);
    
    for (auto it : ans)
    {
        cout << it<< " ";
    }
    cout<<endl;
    for (auto it : ans1)
    {
        cout << it<< " ";
    }
    return 0;
}