n = input("숫자 여러 개 입력 > ")
l = n.split()
sum = 0
print(l)
print(f"가장 큰 값: {max(l)}\n가장 작은 값: {min(l)}")
l.remove(max(l))
l.remove(min(l))
for i in l:
    sum += int(i)
print(f"나머지 값의 평균: {sum/len(l)}")