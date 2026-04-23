#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i+1;
        }
    }
    return -1;   
}

int main()
{
    int num = 5;
    int arr[6] = {1,4,6,7,5,8};
    cout<< linearSearch(arr, 6, num) << endl;
    return 0;
}