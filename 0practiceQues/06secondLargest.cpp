#include<iostream>
#include<vector>
using namespace std;
int secondLargest(vector<int> arr)
{
    int largest = arr[0];
    int secondLarge = INT_MIN;
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] > largest){
            secondLarge = largest;
            largest = arr[i];
        }
    }
    return secondLarge;
}
int main()
{
    vector<int> arr = {2,1,-1,-5,7,4,9};
    cout<< secondLargest(arr);
    return 0;
}