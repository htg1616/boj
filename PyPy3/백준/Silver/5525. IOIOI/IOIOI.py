n = int(input())
l = 2*n+1
m = int(input())
s = input()
cnt = 0
for i in range(m-l+1):
    if s[i:i+l] == 'I'+'OI'*n:
        cnt += 1
print(cnt)
