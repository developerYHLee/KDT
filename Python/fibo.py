def fibo(n):
    if n == 0 or n == 1:
        return 1

    return fibo(n - 1) + fibo(n - 2)

n = int(input())
for i in range(n):
    print(fibo(i), end=" ")