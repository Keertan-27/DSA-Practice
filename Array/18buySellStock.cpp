#include <iostream>
#include <vector>
using namespace std;
// Buy and sell stock for max profit (we can only sell after buying the stock)
int buySellStockMaxProfit(vector<int> prices)
{
    int profit = 0;
    int minValue = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        int cost = prices[i] - minValue;
        profit = max(profit, cost);

        minValue = min(minValue, prices[i]);
    }
    return profit;
}

int main()
{
    vector<int> prices = {7, 1, 3, 4, 2, 6, 1, 8};
    int ans = buySellStockMaxProfit(prices);
    cout<< ans;
    return 0;
}