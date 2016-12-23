#fname='input2.c'
fname=input("Input file name: ")
fin=open(fname,'r')
A=fin.readlines()
N=len(A)
fin.close()
macros=[]   #list
params={}   #dict
value={}
fout=open(fname.replace('in','out'),'w')
for i in range(N):
    line=A[i]
    if 'main(' in line:
        break
    else:
        if '#define' not in line:
            fout.write(line)
        else:
            S=line.split()
            mac=S[1]
            val=S[2]
            if mac[-1]!=')':
                macros.append(mac)
                params[mac]=[]
                value[mac]=val
            else:
                j=mac.index('(')
                m=mac[:j+1]
                p=mac[j+1:-1].split(',')
                macros.append(m)
                params[m]=p
                value[m]=val
#print (macros,params,value)
ind=i
for i in range(ind,N):
    line=A[i]
    flag=True
    while flag:
        flag=False
        for mac in macros:
            if mac in line:
                flag=True
                if len(params[mac])==0:
                    line=line.replace(mac,value[mac])
                else:
                    j=line.index(mac)
                    x=j+len(mac)
                    T=[]
                    P=[]
                    prev=x
                    for k in range(x,len(line)):
                        if line[k]=='(':
                            T.append('(')
                        elif line[k]==')':
                            if len(T)==0:
                                P.append(line[prev:k])
                                break
                            else:
                                T.pop()
                        elif line[k]==',':
                            if len(T)==0:
                                P.append(line[prev:k])
                                prev=k+1
                    #P=line[x:k].split(',')
                    Q=params[mac]
                    #print (P,Q)
                    T={}
                    for l in range(len(Q)):
                        T[Q[l]]=P[l]
                    V=value[mac]
                    for p in Q:
                        V=V.replace(p,T[p])
                    line=line.replace(line[j:k+1],V)
    fout.write(line)
fout.close()
print("Done! Check file",fname.replace('in','out'),"for the output.")




