def searchElemntRoated(arr, k):
    n = len(arr)
    low, high = 0, n-1

    while low<= high:
        mid = (low+high) // 2
        if arr[mid] == k:
            return mid
        if arr[low] <= arr[mid]:
            if arr[low]<=k & k <= arr[mid]:
                high = mid-1
            else: 
                low = mid +1
        else:
            if arr[mid] <= k & k < arr[high]:
                low = mid +1
            else:
                high = mid-1

    return -1

if __name__ == "__main__":
    arr = [7,8,9,1,2,3,4,5,6]
    ans = searchElemntRoated(arr,1)
    print(f"Element is at index: {ans}")