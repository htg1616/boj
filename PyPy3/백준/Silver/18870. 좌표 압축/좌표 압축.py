import sys
input = sys.stdin.readline
n = int(input())
nums = list(map(int, input().split()))
unique_nums = sorted(set(nums))
idx_dict = {unique_nums[i]:i for i in range(len(unique_nums))}
for i in nums:
    print(idx_dict[i], end=' ')
