'''
서울 지하철 어지러워..

간선과 노드의 개수가 같다 -> 하나의 사이클만 있다는 것이 보장됨

2호선: 51개 역 [노드: 51, 양방향 간선: 51]
-> 순환선 1개, 지선 2개
순환선: 한 역에서 출발해서 계속 가면 출발역으로 돌아올 수 있음
지선: 순환선에 속하는 한 역에서 시작하는 트리 형태 노선
--> 신도림, 성수가 트리의 루트!

역 사이 거리: 지나는 간선의 개수의 최솟값
-> 각 역과 순환선 사이의 거리 구하기

입력: N
역과 역 사이를 연결하는 정보. 중복 X
-> 순환선 내부의 역은 거리가 0

지선에서, 루트와 나머지 노드 사이의 거리만 구하면 되네


순환선은 사이클임. 핵심이 되는 노드는: 순환선과 지선을 연결하는 노드: 성수, 신도림
-> 잘 보니까 저런 포인트는 edge가 2개보다 많음 -> 이 지점이 핵심 지점
두 가지 풀이가 가능함

(1)
-> 이 지점에서 dfs, union-find로 사이클 판별 -> 사이클은 0, 나머지는 bfs로 거리찾기

(2)
-> 지선의 마지막: edge가 1임. -> 역으로 저 지점까지 탐색하고, 나머지는 전부 0처리
'''


## Sol(2) -> 예외가 있음. [Ex(5)] 1번 풀이 해야함.
'''
import sys

def search(start_node, graph, parent):
    tmp_node = []
    tmp_node.append(start_node)

    current_node = start_node
    cnt = 0
    while(True):
        cnt += 1
        next_node = graph[current_node][0]
        if next_node in parent:
            for i in range(len(tmp_node)):
                answer[tmp_node[i]] = cnt - i
            break
        current_node = next_node
        tmp_node.append(current_node)


N = int(input())

graph = [[] for _ in range(N)]
answer = [0] * N

for i in range(N):
    x, y = map(int, sys.stdin.readline().split())
    graph[x-1].append(y-1)
    graph[y-1].append(x-1)

parent = []
last_child = []

for i in range(N):
    if len(graph[i]) > 2:
        parent.append(i)
    if len(graph[i]) == 1:
        last_child.append(i)

for child in last_child:
    search(child, graph, parent)

print(' '.join(map(str, answer)))
'''

## Solution 1.
'''
사이클, 방문을 판단하는 정보가 필요함

1. 각 노드들이 사이클인지 아닌지 판단 [dfs, 바로 되돌아오지 않고 최소 하나 이상의 다른 노드를 거쳐서 돌아오기]
2. 사이클이면서 방문하지 않았다면 bfs 돌려 <- 모든 노드에 대해 적용
-> if cycle: answer = 0, else answer = 이전 노드 + 1

구현이 너무 빡세다. 연습이 부족한듯.. 이참에 union-find를 활용하는 알고리즘 공부해보기
'''

import sys
from collections import deque
sys.setrecursionlimit(1000000)

def dfs(start_node, index, count):
    global is_cycle

    if start_node == index and count >= 2:
        is_cycle = True
        answer[start_node] = 0
        cycle_list[start_node] = True
        return
    
    visited[start_node] = True

    for node in graph[start_node]:
        next_node = node
        if visited[next_node] == False:
            dfs(next_node, index, count + 1)
        else:
            if next_node == index and count >= 2:
                dfs(next_node, index, count)
        
        if is_cycle == True:
            answer[start_node] = 0
            cycle_list[start_node] = True
            return

def bfs(start_node):
    queue = deque([start_node])
    visited = [False] * N
    visited[start_node] = True

    while queue:
        current_node = queue.popleft()
        current_distance = answer[current_node]

        for next_node in graph[current_node]:
            if not visited[next_node]:
                visited[next_node] = True
                if not cycle_list[next_node]:
                    answer[next_node] = current_distance + 1
                    queue.append(next_node)

N = int(input())

graph = [[] for _ in range(N)]
answer = [-1] * N
cycle_list = [False] * N
is_cycle = False

for i in range(N):
    x, y = map(int, sys.stdin.readline().split())
    graph[x-1].append(y-1)
    graph[y-1].append(x-1)

## Step 1. 사이클 판별
for i in range(N):
    visited = [False] * N
    is_cycle = False
    dfs(i, i, 0)

## Step 2. 거리 구하기
for node in range(N):
    if cycle_list[node]:
        bfs(node)

print(' '.join(map(str, answer)))
       