#include <iostream>
using namespace std;

int majority_element(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int cnt = 0;
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
                cnt++;
        }
        if (cnt>arr.size() / 2)
            return arr[i];
    }
    return -1;
}

int majorityElementBetter(vector<int> arr)
{
    int element = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (cnt == 0)
        {
            element = arr[i];
        }
        if (arr[i] == element)
        {
            cnt++;
        }
        else{
            cnt--;
        }
    }
    
    return element;
}
int main()
{
    vector<int> arr = {2,3,3,2,3,4,3};
    int ans = majorityElementBetter(arr);
    cout<<ans;
    return 0;
}