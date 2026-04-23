#include <iostream>
using namespace std;

int findlargest(int arr[], int n){
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}
int main()
{
    int arr[6] = {5, 1, 4, 5, 6, 7};
    cout << findlargest(arr, 6) << endl;
    
    return 0;
}