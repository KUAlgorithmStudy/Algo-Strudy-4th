'''
BFS 좌표유형에서 dx, dy를 나이트의 이동 경로에 맞게 수정하는 문제
'''

import sys
from collections import deque

dx = [-2, -1, 1, 2, 2, 1, -1, -2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]

def bfs(start_x, start_y, end_x, end_y, I):
    if start_x == end_x and start_y == end_y:
        return 0  

    queue = deque([(start_x, start_y)])
    graph = [[0] * I for _ in range(I)]

    while queue:
        x, y = queue.popleft()
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < I and 0 <= ny < I:
                if nx == end_x and ny == end_y:
                    return graph[x][y] + 1
                if graph[nx][ny] == 0:
                    graph[nx][ny] = graph[x][y] + 1
                    queue.append((nx, ny))
        
T = int(sys.stdin.readline().strip())

for _ in range(T):
    I = int(sys.stdin.readline().strip())
    start_x, start_y = map(int, sys.stdin.readline().split())
    end_x, end_y = map(int, sys.stdin.readline().split())

    print(bfs(start_x, start_y, end_x, end_y, I))