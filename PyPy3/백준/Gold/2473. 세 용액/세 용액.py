n = int(input())
arr = sorted(list(map(int, input().split())))

min_sum = int(1e10)
for i in range(n-2):
    left = i+1
    right = n-1
    while left < right:
        sums = arr[i] + arr[left] + arr[right]
        if abs(sums) < min_sum:
            min_sum = abs(sums)
            ans = (arr[i], arr[left], arr[right])
        if sums >= 0:
            right -=1
        else:
            left += 1
print(*ans)
