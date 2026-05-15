
def firstAppearance(arr, x):
    n = len(arr)
    low, high = 0, n - 1
    first = -1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == x:
            first = mid
            high = mid - 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            low = mid + 1

    return first

def lastAppearance(arr, x):
    n = len(arr)
    low, high = 0, n - 1
    last = -1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == x:
            last = mid
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            low = mid + 1

    return last


if __name__ == "__main__":
    arr = [2, 5, 6, 8, 10, 10, 10, 10, 14, 16, 32]
    target = int(input("Enter target value: "))

    first = firstAppearance(arr, target)
    last = lastAppearance(arr, target)

    print(f"First appearance is at: {first}")
    print(f"Last appearance is at: {last}")