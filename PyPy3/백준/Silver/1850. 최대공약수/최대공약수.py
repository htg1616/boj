a, b = map(int, input().split())
def gcd(a, b):
    return a if b==0 else gcd(b, a%b)

for i in range(gcd(a, b)):
    print(1, end='')