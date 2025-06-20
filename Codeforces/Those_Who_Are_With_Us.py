t = int(input())
for _ in range(t):
    n,m= map(int,input().split())
    matrix = []
    for i in range(n): 
        row = (list(map(int,input().split())))
        matrix.append(row)

    stack = []
    a = max(matrix)
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == a: stack.append([i,j])

    
