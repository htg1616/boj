n = int(input())
a = 0
b = 1
for _ in range(n-1):
    a, b = b, a+b
if n!= 0:
    print(b)
else:
    print(0)