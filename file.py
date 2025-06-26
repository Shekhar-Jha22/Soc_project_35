import math

n=int(input())
def hanoi(n,l,r,m):
    if n==1:
        print(l," ",r)
    else:
        hanoi(n-1,l,m,r)
        print(l," ",r)
        hanoi(n-1,m,r,l)

print(math.pow(2,n)-1)
hanoi(n,1,3,2)