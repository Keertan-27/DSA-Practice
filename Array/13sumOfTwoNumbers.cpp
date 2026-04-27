#include<iostream>
#include<vector>
#include<map>
using namespace std;

pair<int,int> sumOfTwoNumbersWithValueBetter(vector<int> a, int k)
{
    map<int, int> valueMapping;

    for (int i = 0; i < a.size(); i++)
    {
        int remValue = k-a[i];
        
        if (valueMapping.find(remValue) != valueMapping.end())
        {
            cout<< "True";
            return {valueMapping[remValue] +1, i+1};
        }

        valueMapping[a[i]] = i;
    }
    return {-1,-1};
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

    return 0;
}