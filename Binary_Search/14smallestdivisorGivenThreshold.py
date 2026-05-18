def smallestDivisiorThreshold(arr, thresh):
    n = len(arr)
    if n>thresh: return -1
    low, high = 1, max(arr)
    while low <= high:
        mid = (low+high) //2
        sum = 0
        for i in range(n):
            sum = sum + (mid + arr[i] -1) // mid

        if sum <= thresh:
            high = mid -1
        else:
            low = mid +1
    return low

if __name__ == "__main__":
    arr = [1,2,5,9]
    threshold = 6

    ans = smallestDivisiorThreshold(arr, threshold)
    print(ans)