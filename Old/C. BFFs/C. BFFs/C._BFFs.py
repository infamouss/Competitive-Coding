from collections import defaultdict

def DFS(G,v,seen=None,path=None):
    if seen is None: seen = []
    if path is None: path = [v]

    seen.append(v)

    paths = []
    for t in G[v]:
        if t not in seen:
            t_path = path + [t]
            paths.append(tuple(t_path))
            paths.extend(DFS(G, t, seen, t_path))
    return paths


#edges = [['1', '2'], ['2', '4'], ['1', '11'], ['4', '11']]
edges=[]
n=int(input())
list1=input().split()

i=1
for element in list1:
    edges.append([i,element])
    i=i+1




G = defaultdict(list)
for (s,t) in edges:
    G[s].append(t)
    G[t].append(s)

#print G.items()

all_paths = DFS(G, '1')
max_path  = max(all_paths, key=lambda l: len(l))
print("All Paths:")
print(all_paths)
print("Longest Path:")
print(max_path)
print("Longest Path Length:")
print(len(max_path))