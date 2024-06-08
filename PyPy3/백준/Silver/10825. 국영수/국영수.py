n = int(input())
data = []
for i in range(n):
    line = input().split()
    name = line[0]
    scores = list(map(int, line[1:]))
    data.append([name] + scores)
data.sort(key=lambda x: (-x[1], x[2], -x[3], x[0]))
for i in data:
    print(i[0])