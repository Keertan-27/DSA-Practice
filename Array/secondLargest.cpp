#include <iostream>
using namespace std;

int findSecondlargestBetter(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    int seclargest = arr[-1];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > seclargest && arr[i] != largest)
        {
            seclargest = arr[i];
        }
    }

    return seclargest;
}

int findSecondlargest(int arr[], int n)
{
    int largest = arr[0];
    int secondlarge = arr[-1];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondlarge = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secondlarge)
        {
            secondlarge = arr[i];
        }
    }
    return secondlarge;
}

int main()
{
    int arr[6] = {3, 5, 9, 6, 5, 7};
    cout << findSecondlargestBetter(arr, 6) << endl;
    cout << findSecondlargest(arr, 6) << endl;
    return 0;
}