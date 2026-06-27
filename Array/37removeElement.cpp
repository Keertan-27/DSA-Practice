#include <iostream>
using namespace std;
int removeElement(vector<int> &arr, int val)
{
    int i = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] != val)
        {
            arr[i] = arr[j];
            i++;
        }
    }
    return i;
}
int main()
{
    vector<int> arr = {2,3,2,2,2,2,3};
    int ans = removeElement(arr, 3);
    cout<<ans;
    return 0;
}