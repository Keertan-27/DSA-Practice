// rotate an array by k position 
#include <iostream>
using namespace std;
// better solution 
void rorateArray(int arr[], int n, int k){
    k = k%n;
    // inserting into temp 
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = k; i < n; i++)
    {
        arr[i-k] = arr[i];
    }

    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - (n-k)];
    }
}

// optimal solution 
void leftRotate(int arr[], int n, int k)
{
    reverse(arr, arr+k);
    reverse(arr+k, arr+n);
    reverse(arr, arr+n);
}
int main()
{
    int arr[6] = {1,2,3,4,5,6};
    int rotateBy = 2;
    leftRotate(arr, 6, rotateBy);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}