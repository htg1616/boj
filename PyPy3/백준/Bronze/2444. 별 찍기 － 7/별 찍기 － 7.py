n = int(input())
for i in range(n):
    print(' '*(n-1-i) + '*'*(2*i+1))
for i in range(n-1):
    print(' '*(1+i) + '*'*(2*n-3-2*i))