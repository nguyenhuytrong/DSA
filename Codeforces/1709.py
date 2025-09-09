t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))

    ops = []

    while True:
        changed = False

        # Fix a[i] >= b[i] by swapping
        for i in range(n):
            if a[i] >= b[i]:
                a[i], b[i] = b[i], a[i]
                ops.append((3, i+1))
                changed = True

        # Fix a not strictly increasing
        for i in range(n - 1):
            if a[i] >= a[i + 1]:
                a[i], a[i + 1] = a[i + 1], a[i]
                ops.append((1, i+1))
                changed = True

        # Fix b not strictly increasing
        for i in range(n - 1):
            if b[i] >= b[i + 1]:
                b[i], b[i + 1] = b[i + 1], b[i]
                ops.append((2, i+1))
                changed = True

        if not changed:
            break

    print(len(ops))
    for op in ops:
        print(op[0], op[1])
