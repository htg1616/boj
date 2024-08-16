import sys
input = sys.stdin.readline

while (n := int(input())) != -1:
    factor = []
    for i in range(1, n):
        if n % i == 0:
            factor.append(i)
    if sum(factor) == n:
        print(f"{n} = ", end='')
        print(*factor, sep=' + ')
    else:
        print(f"{n} is NOT perfect.")