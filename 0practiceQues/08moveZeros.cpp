#include <iostream>
#include <vector>
using namespace std;
void moveZeros(vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        while (j < arr.size() && arr[i] == 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

void moveZerosOpt(vector<int> &arr)
{
    int idx = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            arr[idx] = arr[i];
            idx++;
        }
    }

    for (int i = idx; i < arr.size(); i++)
    {
        arr[i] = 0;
    }
}

void moveZerosNe(vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
           swap(arr[i], arr[j]);
           j++;
        }
    }
}
int main()
{
    vector<int> arr = {0, 1, 0, 3, 12, 4};
    moveZerosNe(arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}