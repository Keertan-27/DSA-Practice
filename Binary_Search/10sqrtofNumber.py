def sqrtNumber(n):
    low, high = 0, n
    ans = 1
    while(low<=high):
        mid = (low+high) //2
        if (mid*mid) <= n:
            ans = mid
            low = mid+1
        else:
            high = mid-1
    return ans

n = 25
ans = sqrtNumber(n)
print(ans)
