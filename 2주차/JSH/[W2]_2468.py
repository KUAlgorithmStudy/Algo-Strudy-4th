'''
지역의 한계 강수량이 주어질 때, 모든 강수량에 대해 가장 많은 안전지대가 생성되는 수 찾기
-> N = 100, 1초 -> N^3까지 가능

지역별로 주어진 높이들에 대해서 모두 탐색하기
물에 항상 안잠기는 경우도 있을 수 있음

간단하게 생각해보자.
N = k라고 가정 -> 그래프 내에서 각 지역의 최대 강수량을 h라고 할 때, h<=k인 지역은 나가리
-> 0으로 가정하고 bfs/dfs 돌려서 탐색 가능한 지역 찾기
-> answer_list 추가
-> N^2 [탐색 및 처리]


나중에 max(answer_list 해보기)

'''
import sys
sys.setrecursionlimit(1000000)

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def dfs(start_x, start_y, rain):
    for i in range(4):
        nx = start_x + dx[i]
        ny = start_y + dy[i]

        if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny] and graph[nx][ny] > rain:
            visited[nx][ny] = True
            dfs(nx, ny, rain)


N = int(input())
graph = []
max_height = 0

for _ in range(N):
    graph.append(list(map(int, sys.stdin.readline().split())))
    max_height = max(max_height, max(graph[-1]))

answer = 1

for i in range(max_height):
    count = 0
    visited = [[0] * N for _ in range(N)]
    for x in range(N):
        for y in range(N):
            if graph[x][y] > i and visited[x][y] == 0:
                visited[x][y] = True
                count += 1
                dfs(x, y, i)
    answer = max(answer, count)

print(answer)