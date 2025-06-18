def solve():
    n, s = map(int, input().split())
    x = list(map(int, input().split()))
    
    res = 0
    if s <= x[0]:
        res = x[-1] - s
    elif s >= x[-1]:
        res = s - x[0]
    else:
        res = min(abs(s - x[0]) + x[-1] - x[0], abs(s - x[-1]) + x[-1] - x[0])
    
    print(res)

t = int(input())
for _ in range(t):
    solve()
