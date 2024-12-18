def bubble_sort(lst):
    n = len(lst)
    for i in range(n):
        for j in range(0,n-1):
            if lst[j]>lst[j+1]:
                lst[j+1],lst[j] = lst[j],lst[j+1]

def sel_sort(lst):
    n = len(lst)
    for i in range(n-1):
        mindex = i
        for j in range(i+1,n):
            if lst[j]<lst[mindex]:
                mindex = j
        temp = lst[mindex]
        lst[mindex] = lst[i]
        lst[i] = temp

def insertion_sort(arr):
    n = len(arr)
    for i in range(n):
        j = i
        while j>0 and arr[j-1]>arr[j]:
            arr[j-1],arr[j] = arr[j],arr[j-1]
            j -= 1

def shell_sort(arr):
    n = len(arr)
    gap = n//2
    while gap>0:
        j = gap
        while j<n:
            i = j-gap
            while i>=0:
                if arr[i+gap]>arr[i]:
                    break
                else:
                    arr[i+gap],arr[i] = arr[i],arr[gap+i]
                i = i -gap
            j += 1
        gap = gap//2



d = [2,5,4,3,1]
bubble_sort(d)
print(d)
