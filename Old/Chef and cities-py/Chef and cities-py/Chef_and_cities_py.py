def firstDigit(N):
    while N//10>0:
        N=N//10
    return N



N=int(input())
F = list(map(int, input().split()))
Q=int(input())
while Q>0:
    type=list(map(int, input().split()))
    if len(type)==3:
        F[type[1]-1]=type[2]
    else:
        i=0
        ans=1
        while i<N:
            ans=ans*F[i]
            i=i+type[1]
        print(firstDigit(ans),end="")
        print(" ",end="")
        print(ans%1000000007)
    Q=Q-1
