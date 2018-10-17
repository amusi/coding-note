import math

def BinarySearch(arr, key):
    left = 0
    right = len(arr)-1

    while left <= right:
        mid = math.ceil((left+right)/2)
        if arr[mid] == key:
            return 1
        elif arr[mid]<key:
            left = mid+1
        else:
            right = mid-1
    return 0


arr = [10,20,-9,-10,100,-100,77,88,33,21]
arr.sort()
if BinarySearch(arr, -9):
    print("Yes")
else:
    print("No")
