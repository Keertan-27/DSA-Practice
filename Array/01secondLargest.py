def secondLargestArr(arr):
    n = len(arr)
    largest = arr[0]
    secondlargest = arr[-1]
    for i in range(n):
        if arr[i] > largest:
            secondlargest = largest
            largest = arr[i]
        elif arr[i] < largest & arr[i]> secondlargest:
            secondlargest = arr[i]
    return secondlargest

if __name__ == "__main__":
    arr = [2,5,7,9,1,4,14]
    ans = secondLargestArr(arr)
    print(f"Second largest: {ans}")