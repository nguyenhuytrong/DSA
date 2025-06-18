t = int(input())

count = [0] * 150
for _ in range (t):
    count = [0] * 150
    n = int(input())
    s = input()
    count[ord(s[0])] += 1
    count[ord(s[n-1])] += 1
    i = 1
    ans = 0
    while i < n-1: 
        if count[ord(s[i])] == 0: 
            count[ord(s[i])] += 1
            i+=1
        else: 
            ans += 1
            break
    if ans == 0: print("No")
    else: print("Yes")
        
