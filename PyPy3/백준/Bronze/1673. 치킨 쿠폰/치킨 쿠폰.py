import sys
input = sys.stdin.readline
while line:= input():
    n, k = map(int, line.split())
    print(n + (n-1)//(k-1))