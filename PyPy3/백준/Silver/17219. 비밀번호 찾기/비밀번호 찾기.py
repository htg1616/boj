import sys
input = sys.stdin.readline
n, m = map(int, input().split())

pw_dict = {}
for i in range(n):
    site, pw = input().rstrip().split()
    pw_dict[site] = pw
for i in range(m):
    site = input().rstrip()
    print(pw_dict[site])