#include <iostream>
using namespace std;
int removeDuplicateII(vector<int> &arr)
{
    if (arr.size()<=2)
        return arr.size();
    
    int i = 2;
    for (int j = 2; j < arr.size(); j++)
    {
        if (arr[i-2] != arr[j])
        {
            arr[i] = arr[j];
            i++;
        }
    }
    return i;
}
int main()
{
    vector<int> arr = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int ans = removeDuplicateII(arr);

    for (int i = 0; i < ans; i++)
    {
        cout<< arr[i] << " ";
    }
    
    return 0;
}