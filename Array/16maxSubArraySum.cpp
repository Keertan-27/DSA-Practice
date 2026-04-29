#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySumBetter(vector<int> a)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        int sum =0;
        for (int j = i; j < a.size(); j++)
        {
            sum += a[j];
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

pair<int,int> maxSubArrayOptimal(vector <int> a)
{
    int maxSum = INT_MIN;
    int sum =0;
    int ansStart = -1, ansEnd = -1;
    int start = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if(sum == 0)
        {
            start = i;
        }
        sum += a[i];

        if (sum>maxSum)
        {
            maxSum = sum;
            ansStart = start, ansEnd = i;
        }
        if(sum<0){
            sum =0;
        }
    }
    return {ansStart, ansEnd};
}
int main()
{
    vector<int> arr = {-2, 4,-1, 7, -3, 1, 2};
    pair<int, int> ans = maxSubArrayOptimal(arr);
    cout << ans.first<< " "<< ans.second<<endl;
    for (int i = ans.first; i <= ans.second; i++)
    {
        cout<< arr[i]<< " ";
    }
    
    return 0;
}