import sys

n = int(input())
list = []
for i in range(n):
    line = sys.stdin.readline().split()

    if line[0] == "push":
        list.insert(0, line[1])
    elif line[0] == "pop":
        if(len(list) <= 0): print("-1")
        else:
            print(list[0])
            list.remove(list[0])
    elif line[0] == "size":
        print(len(list))
    elif line[0] == "empty":
        if (len(list) == 0): print(1)
        else: print(0)
    elif line[0] == "top":
        if (len(list) <= 0): print("-1")
        else: print(list[0])