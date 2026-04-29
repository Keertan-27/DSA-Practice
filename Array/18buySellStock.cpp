#include <iostream>
#include <vector>
using namespace std;
// Buy and sell stock for max profit (we can only sell after buying the stock)
int buySellStockMaxProfit(vector<int> a)
{
    int profit = 0;
    int minValue = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        int cost = a[i] - minValue;
        profit = max(profit, cost);

        minValue = min(minValue, a[i]);
    }
    return profit;
}

int main()
{
    vector<int> arr = {7, 1, 3, 4, 2, 6, 1, 8};
    int ans = buySellStockMaxProfit(arr);
    cout<< ans;
    return 0;
}