'''
간단한 그래프 문제임
-> 노드는 첨에 false로 놓고, 방문하면 true

각 노드에 대해 dfs / bfs 시작
-> 이어지는 노드가 있다면 cnt += 1하고, 방문처리하는 dfs / bfs
-> 없으면 다음 노드로

-> 전체 cnt 출력
'''
import sys
sys.setrecursionlimit(10**6)

def dfs(start):
    visited[start] = True

    for i in graph[start]:
        if not visited[i]:
            dfs(i)

N, M = map(int, sys.stdin.readline().split())

visited = [False] * (N+1)
answer = 0
graph = [[] for _ in range(N+1)]

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

for i in range(1, N+1):
    if not visited[i]:
        dfs(i)
        answer += 1

print(answer)