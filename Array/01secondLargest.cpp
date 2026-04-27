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

int findSecondSmall(int arr[], int n)
{
    int smallest = arr[0];
    int secondsmall = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondsmall = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < secondsmall)
        {
            secondsmall = arr[i];
        }
    }
    return secondsmall;
}

int main()
{
    int arr[10] = {3, 5, 9, 6, 5, 7, 10, 20, 1, 2};
    cout << findSecondlargest(arr, 10) << endl;
    cout << findSecondSmall(arr, 10) << endl;
    return 0;
}