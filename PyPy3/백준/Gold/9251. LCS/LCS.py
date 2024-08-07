s1 = input()
s2 = input()
n1 = len(s1)
n2 = len(s2)
s1 = ' '+s1
s2 = ' '+s2

table = [[0 for j in range(n2+1)] for i in range(n1+1)]

'''
def dp(x, y):
    if x==0 or y==0:
        return 0
    if table[x][y] != 0:
        return table[x][y]
    
    table[x][y] = max(dp(x-1, y), dp(x, y-1))
    if s1[x] == s2[y]:
        table[x][y] = max(table[x][y], dp(x-1, y-1) + 1)
    return table[x][y]
'''
for i in range(1, n1+1):
    for j in range(1, n2+1):
        table[i][j] = max(table[i-1][j], table[i][j-1])
        if s1[i] == s2[j]:
            table[i][j] = max(table[i][j], table[i-1][j-1] + 1)


print(table[n1][n2])