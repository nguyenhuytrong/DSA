def solve():
    a, x, y = map(int, input().split())
    if x > y:
        x, y = y, x  # đảm bảo x <= y

    for b in range(1, 101):
        if b == a:
            continue
        if abs(b - x) < abs(a - x) and abs(b - y) < abs(a - y):
            print("YES")
            return
    print("NO")

t = int(input())
for _ in range(t):
    solve()