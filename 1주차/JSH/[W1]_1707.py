'''
정점 집합 0 = {0, 0, 0, ...}
정점 집합 1 = {1, 1, 1, ...}

위 조건이 임의의 분할에 대해 만족해야 함.

그래프의 시작 노드를 True로 잡아보자. 



'''
import sys
from collections import deque

def bfs(start, node):
    queue = deque([start])
    visited[start] = node

    while queue:
        node = queue.popleft()
        for next_node in graph[node]:
            if not visited[next_node]:
                queue.append(next_node)
                visited[next_node] = -visited[node]
            elif visited[next_node] == visited[node]:
                return False
    return True

K = int(input())

for _ in range(K):
    V, E = map(int, sys.stdin.readline().split())

    graph = [[] for _ in range(V+1)]
    visited = [False] * (V+1)
    
    for _ in range(E):
        u, v = map(int, sys.stdin.readline().split())
        graph[u].append(v)
        graph[v].append(u)
    
    for i in range(1, V+1):
        if not visited[i]:
            result = bfs(i, 1)
            if not result:
                break

    print("YES" if result else "NO")