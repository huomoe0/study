n = int(input())
a = 1
ans = 0
for i in range(1,n+1):
    a *= i
    ans += a
print(ans)