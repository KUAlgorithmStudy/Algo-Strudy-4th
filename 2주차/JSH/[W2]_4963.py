import sys
from collections import deque

def bfs(start_x, start_y, graph):
    dx = [1, 1, 1, -1, -1, -1, 0, 0]
    dy = [0, 1, -1, 0, 1, -1, 1, -1]
    
    queue = deque([(start_x, start_y)])
    graph[start_x][start_y] = 0

    while queue:
        x, y = queue.popleft()

        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < len(graph) and 0 <= ny < len(graph[0]):
                if graph[nx][ny] == 1:
                    graph[nx][ny] = 0
                    queue.append((nx, ny))

while(True):
    w, h = map(int, sys.stdin.readline().split())
    if w == 0 and h == 0:
        break

    graph = []
    for _ in range(h):
        row = list(map(int, sys.stdin.readline().split()))
        graph.append(row)

    answer = 0
    for x in range(h):
        for y in range(w):
            if graph[x][y] == 1:
                bfs(x, y, graph)
                answer += 1
    print(answer)
