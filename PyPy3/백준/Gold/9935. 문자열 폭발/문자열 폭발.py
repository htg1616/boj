string = input()
exp = input()

stack = []
l = len(exp)
for i in string:
    stack.append(i)
    if len(stack) >= l and ''.join(stack[-l:]) == exp:
        for _ in range(l):
            stack.pop()

if stack:
    print(*stack, sep='')
else:
    print('FRULA')