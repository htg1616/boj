n = int(input())
score = [int(input()) for i in range(n)]
if n==0:
    print(0)
else:
    score.sort()
    cut = int(n*0.15+0.5)
    score = score[cut:n-cut]
    avg = int(sum(score)/len(score)+0.5)
    print(avg)