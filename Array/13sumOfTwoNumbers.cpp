#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
// for returning bool as well as indexes we can use this
pair<int,int> sumOfTwoNumbersWithValueBetter(vector<int> a, int k)
{
    map<int, int> valueMapping;

    for (int i = 0; i < a.size(); i++)
    {
        int remValue = k-a[i];
        
        if (valueMapping.find(remValue) != valueMapping.end())
        {
            return {valueMapping[remValue] +1, i+1};
        }

        valueMapping[a[i]] = i;
    }
    return {-1,-1};
}
// only to return bool 
void sumOfTwoNumbersWithValueTwoPointer(vector<int> a, int k){
    int n = a.size();
    int i = 0;
    int j = n - 1;
    sort(a.begin(), a.end());
    while (i < j)
    {
        int sum = a[i] + a[j];
        if (sum == k)
        {
            cout << "Yes";
            return;
        }
        else if (sum > k) j--;
        else i++;
    }
    cout << "No";
}
int main()
{
    vector<int> arr = {2,5,6,7,8,2};
    int k = 14;
    pair <int,int> ans = sumOfTwoNumbersWithValueBetter(arr, k);
    // indexing will start from 1
    if(ans.first != -1)
        cout<< "True: "<< ans.first << " "<< ans.second;
    else
        cout<<"False";

    cout<< endl;
    sumOfTwoNumbersWithValueTwoPointer(arr,k);

    return 0;
}