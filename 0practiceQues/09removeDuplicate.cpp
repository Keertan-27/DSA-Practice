#include<iostream>
#include<vector>
using namespace std;

int removeDuplicate(vector<int> &arr)
{
    int left = 0;
    int right = 0;
    for (int right = 0; right < arr.size(); right++)
    {
        if (arr[left] != arr[right])
        {
            left++;
            swap(arr[left], arr[right]);
        }
        
    }
    return left+1;
}
int main()
{
    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    cout<< removeDuplicate(arr)<< endl;
    for(auto x: arr){
        cout<< x<< " ";
    }
    return 0;
}