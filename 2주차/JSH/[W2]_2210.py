'''
숫자판 -> 0-9까지 숫자 있음
-> 임의의 위치에서 시작 -> 4방향에 인접한 숫자 붙여가는거 -> 5번 이동하고, 재방문 가능
-> brute force + dfs [길이 조건]
-> bfs는 안되는게, 저장이 빡셈. dfs로 하나 완성하고 다음꺼 가는게 깔끔함
'''

import sys
sys.setrecursionlimit(10**6)

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
result = []
graph = []

def dfs(start_x, start_y, string):
    if len(string) == 6:
        result.append(string)
        return

    for i in range(4):
        nx = start_x + dx[i]
        ny = start_y + dy[i]

        if nx < 0 or nx >= 5 or ny < 0 or ny >= 5:
            continue
        else:
            dfs(nx, ny, string + graph[nx][ny])


for _ in range(5):
    row = list(map(str, sys.stdin.readline().split()))
    graph.append(row)

for x in range(5):
    for y in range(5):
        dfs(x, y, graph[x][y])

print(len(set(result)))