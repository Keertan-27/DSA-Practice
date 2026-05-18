#include<iostream>
#include<vector>
using namespace std;

int leastCapicityToShip(vector<int> weights, int days)
{
    int n = weights.size();
    int maxi = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, weights[i]);
        sum += weights[i];
    }
    int low = maxi, high = sum;
    while (low<= high)
    {
        int mid = (low+high) /2;
        int load = 0;
        int numDays = 1;
        for (int i = 0; i < n; i++)
        {
            if(load + weights[i] > mid){
                numDays++;
                load = weights[i];
            }
            else 
                load += weights[i];
        }

        if(numDays <= days){
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main()
{
 vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
 int days = 5;
 int ans = leastCapicityToShip(weights, days);
 cout<<ans;   
}