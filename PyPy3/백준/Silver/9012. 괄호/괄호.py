import sys
input = sys.stdin.readline

def solve():
    a = input().strip()
    st = []
    for i in list(a):
        if i=='(':
            st.append('(')
        elif i==')':
            if len(st) < 1 or st[-1] != '(':
                return False
            st.pop()
    if st:
        return False
    return True

t = int(input())
for _ in range(t):
    if solve():
        print('YES')
    else:
        print('NO')