str1 = input("enter the string: ")
list1 = str1.split()
print("string splitted form: ",list1)
def longest_word(list):
    max = 0
    word = 0
    for i in range(len(list)):
        len(list[i])
        if max < len(list[i]):
            max = len(list[i])
            word = i
    print("longest word in string is: '",list[word],"' and it's length is '",max)

def occur_char(str):
    y = input("enter the character: ")
    a = 0
    for i in range(len(str)):
        if y == str[i]:
            a += 1
    print("the occurance of character '",y,"' is: ",a)

def palindrome():
    substr = input("enter the substring: ")
    if substr[0::] == substr[::-1]:
        print("the given substring '",substr,"' is palindrome.")
    else:
        print("the given substring '", substr, "' is not palindrome.")

def index_substr(list):
    substr = input("enter the substring: ")
    index = 0
    for i in range(len(list)):
        if substr == list[i]:
            break
        else:
            index += len(list[i])
    print("starting index of given substring '",substr,"' is: ",index+1)

def occ_word(list):
    list2 = []
    for i in list:
        for j in list:
            if(i == j and j not in list2):
                list2.append(i)
            else:
                continue

    for i in list2:
        max = 0
        for j in list1:
            if i == j:
                max += 1
            else:
                continue
        print("the number of time'",i,"' is repeated is ",max)

flag = 1
while flag == 1:
    print("\n***---------MENU--------***")
    print("1.longest word: ")
    print("2.occurrance of particular character: ")
    print("3.check palindrome: ")
    print("4.starting index of substring: ")
    print("5.occurrance of each word: ")
    print("6.exit()")
    ch = int(input("enter your choice: "))
    if ch == 1:
        longest_word(list1)
        flag = 1
    elif ch == 2:
        occur_char(str1)
        flag = 1
    elif ch == 3:
        palindrome()
        flag = 1
    elif ch == 4:
        index_substr(list1)
        flag = 1
    elif ch == 5:
        occ_word(list1)
        flag = 1
    elif ch == 6:
        flag = 0
