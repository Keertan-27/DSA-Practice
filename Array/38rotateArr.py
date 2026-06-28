def rotateArr(arr, k):
    n = len(arr)
    temp = [0] * n
    for i in range(n):
        temp[i] = arr[(i+k+1) % n]
    
    return temp

def rotateArrOptimal(arr, k):
    n = len(arr)
    arr[0:n] = arr[0:n][::-1]
    arr[0:k] = arr[0:k][::-1]
    arr[k:n] = arr[k:n][::-1]
    return arr

arr = [1,2,3,4,5,6,7]
k = 3
print(rotateArrOptimal(arr, 3))
