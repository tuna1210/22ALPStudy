from numpy import Inf


inp = input().split()
n = int(inp[0])
k = int(inp[1])

ans = -1
dep = 0
while True:
    print(n)
    if n % k == 0:
        ans = dep;
        break;
    if n > 100000000000000000:
        break;
    
    n = n * (pow(10, len(str(n))) + 1)
    dep += 1

print(ans)