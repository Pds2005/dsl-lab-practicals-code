#set theory concepts
def removeduplicate(d):
    lst = []
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst

def union(lst1,lst2):
    lst3 = lst1.copy()
    for val in lst2:
        if val not in lst1:
            lst3.append(val)
    return lst3

def intersection(lst1,lst2):
    lst3 = []
    for i in lst1:
        if i in lst2:
            lst3.append(i)
    return lst3

def diff(lst1,lst2):
    lst3 = []
    for i in lst1:
        if i not in lst2:
            lst3.append(i)
    return lst3

def symdiff(lst1,lst2):
    d1 = diff(lst1,lst2)
    d2 = diff(lst2,lst1)
    lst3 = union(d1,d2)
    return lst3

#basic concept of program

def cb(lst1,lst2):
    lst3 = intersection(lst1,lst2)
    print("list of student who play both cricket and badminton: ",lst3)
    return len(lst3)

def eceb(lst1,lst2):
    lst3 = symdiff(lst1,lst2)
    print("list of student who play either cricket or badminton: ",lst3)
    return len(lst3)

def ncnb(lst1,lst2,lst3):
    lst4 = diff(lst1,union(lst1,lst2))
    print("student who neither play crickket and nor badminton: ",lst4)
    return len(lst4)

def cfnb(lst1,lst2,lst3):
    lst4 = diff(union(lst1,lst2),lst3)
    print("student who play both cricket and football but not badminton ",lst4)
    return len(lst4)

#students list
secomp = []
n = int(input("enter the number of student in secomp: "))
print("name of the ",n," students: ")
for i in range(0,n):
   ele = input()
   secomp.append(ele)
secomp = removeduplicate(secomp)
print("student in SE COMP: ",secomp)

cricket = []
n = int(input("enter the number of student who play cricket in secomp: "))
print("name of the ",n," students who play cricket: ")
for i in range(0,n):
   ele = input()
   cricket.append(ele)
cricket = removeduplicate(cricket)
print("student in SE COMP who play cricket: ",cricket)

badminton = []
n = int(input("enter the number of student who play badminton in secomp: "))
print("name of the ",n," students who play badminton: ")
for i in range(0,n):
   ele = input()
   badminton.append(ele)
badminton = removeduplicate(badminton)
print("student in SE COMP who play badminton: ",badminton)

football = []
n = int(input("enter the number of student who play football in secomp: "))
print("name of the ",n," students who play football: ")
for i in range(0,n):
   ele = input()
   football.append(ele)
football = removeduplicate(football)
print("student in SE COMP who play football: ",football)

flag = 1
while flag == 1:
    print("\n***-------------MENU--------------***")
    print("\n1.student play both cricket and badminton: ")
    print("\n2.student play either cricket or badminton: ")
    print("\n3.student play not cricket nor badminton: ")
    print("\n4.student play both cricket and football not badminton: ")
    print("\n5.exit")
    ch = int(input("enter your choice: "))
    if ch == 1:
        print("student play both cricket and badminton: ",cb(cricket,badminton))
        a = input("do you want to continue(y/n): ")
        if a == "y":
            flag = 1
        else:
            flag = 0

    elif ch == 2:
        print("student play either cricket or badminton: ",eceb(cricket,badminton))
        a = input("do you want to continue(y/n): ")
        if a == "y":
            flag = 1
        else:
            flag = 0

    elif ch == 3:
        print("student play neither cricket nor badminton: ",ncnb(secomp,cricket,badminton))
        a = input("do you want to continue(y/n): ")
        if a == "y":
            flag = 1
        else:
            flag = 0

    elif ch == 4:
        print("student play both cricket and football not badminton: ",cfnb(cricket,football,badminton))
        a = input("do you want to continue(y/n): ")
        if a == "y":
            flag = 1
        else:
            flag = 0

    elif ch == 5:
        flag = 0
