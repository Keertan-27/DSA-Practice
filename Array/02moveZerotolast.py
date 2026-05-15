def moveZeroToLast(arr): 
    n = len(arr)
    i, j = 0, 0
    while i < n:
        if arr[i] != 0:
            arr[j] = arr[i]
            j += 1
        i += 1

    while j < n:
        arr[j] = 0
        j += 1
    return arr

def moveZeroLastSecondMethod(arr):
    n = len(arr)
    j = -1
    for i in range(n):
        if arr[i] == 0:
            j = i
            break

    if(j == -1):
        return 

    for i in range(j+1, n):
        if(arr[i] != 0):
            arr[i], arr[j] = arr[j], arr[i]
            j += 1

    return arr


if __name__ == "__main__":
    arr = [int(x) for x in input("Enter array elements separated by spaces: ").split()]
    ans = moveZeroLastSecondMethod(arr)
    print(ans)