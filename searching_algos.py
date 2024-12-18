roll_number = []
n = int(input("enter the number of students who attended the program: "))
for i in range(0,n):
    roll = int(input(f"enter the roll number of student {i+1}: "))
    roll_number.append(roll)
print(f"Roll numbers of {n} students that attended program:\t{roll_number}")

#linear search
def linear_search(roll_number,target):
    for i in roll_number:
        if target == i:
            return 1

#sentinel search
def sentinel_search(roll_number,target,n):
    end = roll_number[n-1]
    roll_number[n-1] = target
    i = 0
    while (roll_number[i]!=target):
        i +=1
    roll_number[n-1] = end
    if((i<n-1) or (roll_number[n-1]==target)):
        return 1

roll_number.sort()
s_roll = roll_number
print("sorted order of roll number is:\t",s_roll)

#binary search
def binary_search(s_roll,target,n):
    l = 0
    h = n-1
    while l<=h:
        mid = int((l+h)/2)
        if s_roll[mid] == target:
            return 1
        elif s_roll[mid] <target:
            l = mid+1
        else:
            h = mid-1

#fibbonacci search
def fibb_search(s_roll,target,n):
    fibm2 = 0
    fibm1 = 1
    fibm = fibm2+fibm1
    while(fibm<n):
        fibm2 = fibm1
        fibm1 = fibm
        fibm = fibm2 + fibm1
    offset = -1
    while(fibm>1):
        i = min(offset + fibm2,n-1)
        if(s_roll[i]<target):
            fibm = fibm1
            fibm1 = fibm2
            fibm2 = fibm - fibm1
            offset = i
        elif(s_roll[i]>target):
            fibm = fibm2
            fibm1 = fibm1 - fibm2
            fibm2 = fibm - fibm1
        else:
            return 1

    if(fibm1 and s_roll[offset+1]==target):
        return 1

#options
flag = 1
target = int(input("enter the roll number you want to search: "))
while flag == 1:
    print("\n----- CHOOSE SEARCH TYPE -----")
    print("1 -> Linear search")
    print("2 -> Sentinel search")
    print("3 -> Binary search")
    print("4 -> Fibonacci search")
    print("5 -> Exit")
    ch = int(input("\nChoose an option (1-5):\t"))

    if ch == 1:
        if(linear_search(roll_number,target)):
            print(f"roll number {target} present in the program")
        else:
            print(f"roll number {target} not present in the program")
        flag = 1

    if ch == 2:
        if(sentinel_search(roll_number,target,n)):
            print(f"roll number {target} present in the program")
        else:
            print(f"roll number {target} not present in the program")
        flag = 1

    if ch == 3:
        if(binary_search(s_roll,target,n)):
            print(f"roll number {target} present in the program")
        else:
            print(f"roll number {target} not present in the program")
        flag = 1

    if ch == 4:
        if(fibb_search(s_roll,target,n)):
            print(f"roll number {target} present in the program")
        else:
            print(f"roll number {target} not present in the program")
        flag = 1

    if ch == 5:
        flag = 0
