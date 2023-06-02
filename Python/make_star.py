n = int(input("몇 줄? "))

for i in range(1, n + 1):
    for j in range(i):
        print("*",end="")
    print()

for i in range(1, n + 1):
    for j in range(n, i, -1):
        print(" ",end="")
    for j in range(i):
        print("*",end="")
    print()

for i in range(1, n + 1):
    for j in range(n, i, -1):
        print(" ",end="")
    for j in range(i * 2 - 1):
        print("*",end="")
    print()
