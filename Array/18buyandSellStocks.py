def buySellStocks(prices):
    n =len(prices)
    maxProfit = 0
    minValue = prices[0]
    for i in range(1,n):
        profit = prices[i] - minValue
        maxProfit = max(profit, maxProfit)

        minValue = min(minValue, prices[i])
    return maxProfit

if __name__ == "__main__":
    size = int(input("Enter the size of array: "))
    arr = []
    for _ in range(size):
        element = int(input("Enter element: "))
        arr.append(element)
    print(arr)
    # 7, 1, 3, 4, 2, 6, 1, 8
    ans = buySellStocks(arr)
    print(ans)