epsilon = 1e-9

n = int(input())
nc = list(map(int, input().split()))

m = int(input())
mc = list(map(int, input().split()))

x = list(map(int, input().split()))
a = x[0]
b = x[1]

def f(c, x):
    ans = 0
    for i in c:
        ans *= x
        ans += i

    return ans

if f(nc, a) > f(mc, a) or f(nc, b) < f(mc, b):
    nc, mc = mc, nc

l = a
r = b
while(r - l > epsilon):
    mid = (l+r)/2
    if f(nc, mid) > f(mc, mid):
        r = mid
    else:
        l = mid
    
ans = (l + r)/2
print("%.8f\n" % ans)