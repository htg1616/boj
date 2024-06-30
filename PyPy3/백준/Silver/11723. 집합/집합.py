import sys
input = sys.stdin.readline

m = int(input())
s = set()
for i in range(m):
    line = input().strip()

    if line == 'all':
        s = {j for j in range(1, 21)}
    elif line == 'empty':
        s.clear()
    else:
        a, b = line.split()
        b = int(b)

        if a == 'add':
            s.add(b)
        elif a == 'remove':
            s.discard(b)
        elif a == 'check':
            print(int(b in s))
        elif a == 'toggle':
            if b in s:
                s.remove(b)
            else:
                s.add(b)
