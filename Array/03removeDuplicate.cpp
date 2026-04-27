#include <iostream>
using namespace std;
// this is a sorted array

int removeDuplicate(int arr[], int n){
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] > arr[i]) // arr[j] != arr[i]
        {
            arr[i+1] = arr[j];
            i++;
        }
        
    }
    return i+1;
}
int main()
{
    int arr[10] = {1,1,2,3,4,4,5,5,6,6};
    cout << removeDuplicate(arr, 10) << endl;
    
    return 0;
}