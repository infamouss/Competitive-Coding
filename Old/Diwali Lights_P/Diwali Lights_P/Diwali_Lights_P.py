T=int(input())
while T>0:
    ans=1
    N=int(input())
    ans=(2**N-1)%100000
    print(ans)
    T=T-1