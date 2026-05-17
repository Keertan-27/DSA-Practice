import math
def claculateHourToeat(arr, val):
    n = len(arr)
    totalH = 0
    for i in range(n):
        totalH = totalH + (arr[i]+val-1) // val
    return totalH 

def minTimeToEatBannans(arr, H):
    low, high = 1, max(arr)
    while low<=high:
        mid = (low+high)//2
        totalH = claculateHourToeat(arr, mid)
        if totalH <= H:
            high = mid -1
        else:
            low = mid +1

    return low


pile = [3, 6, 7, 11]
hours = 8
ans = minTimeToEatBannans(pile, hours)
print(ans)