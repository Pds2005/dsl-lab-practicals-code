def avg(marks):
    total = 0
    count = 0
    for mark in marks:
        if mark != -999:
            total += mark
            count += 1
    if count > 0:
        avg = total/count
    else:
        avg = 0
    print("average marks of whole class is: ", avg)

def highest(marks):
    max_mark = -999
    for mark in marks:
        if mark != -999 and mark>max_mark:
            max_mark = mark
    print("highest mark  is: ",max_mark)

def lowest(marks):
    min_mark = 999
    for mark in marks:
        if mark != -999 and mark<min_mark:
            min_mark = mark
    print("lowest mark  is: ",min_mark)

def absentcount(marks):
    count = 0
    for mark in marks:
        if mark == -999:
         count += 1
    print("total absent student: ",count)

def maxfreq(marks):
    lst = []
    a = []
    for i in marks:
        if i != -999:
            a.append(i)

    for i in a:
        if i not in lst:
            lst.append(i)

    
    max = 0
    lst1 = []
    for i in lst:
        for j in a:
            if i == j:
                max +=1
        lst1.append(max)
        max =0
    # print(lst1)
    maxi = -999
    index = 0
    for i in range(len(lst1)):
        if lst1[i]>maxi:
            maxi = lst1[i]
            index = i
    print("most frequent mark ",lst[index]," ocuurs: ",maxi," times!")

student = []
n = int(input("enter the number of students in class: "))
for i in range(0,n):
    mark = int(input(f"marks of student {i+1} "))
    student.append(mark)

flag = 1
while flag == 1:
    print("\n****-------MENU--------****")
    print("1.average: ")
    print("2.highest: ")
    print("3.lowest: ")
    print("4.absentcount: ")
    print("5.most frequent: ")
    print("6.EXIT")
    ch = int(input("enter your  choice: "))
    if ch == 1:
        avg(student)
        flag =1
    elif ch == 2:
        highest(student)
        flag = 1

    elif ch == 3:
        lowest(student)
        flag = 1

    elif ch == 4:
        absentcount(student)
        flag = 1

    elif ch == 5:
        maxfreq(student)
        flag = 1

    elif ch == 6:
        flag = 0
