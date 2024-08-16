# -*- coding: utf-8 -*-
"""[W5]_3190.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/19wobIW2HBMF3IT7oxWxthh77aIk1BVkp
"""

# W5 3190 뱀

from collections import deque


def solve():
    global MAP
    d = 0
    time = 0
    body = deque([(0, 0)])
    nx, ny = 0, 0

    while True:
        nx = nx + moves[d][0]
        ny = ny + moves[d][1]
        time += 1

        # 맵 범위를 벗어나거나 자기 몸에 부딪히면 리턴
        if nx < 0 or ny < 0 or nx >= N or ny >= N or (nx, ny) in body:
            return time

        if MAP[nx][ny] == 'a':
            MAP[nx][ny] = 0 # 사과를 먹으면 꼬리 이동x
        else:
            body.popleft() # 사과를 못 먹으면 꼬리 이동
        body.append((nx, ny)) # 머리가 이동한 칸 추가

        # 방향 정보가 있는 time에 도달하면
        if time in info.keys():
            if info[time] == 'L': # 왼쪽이면
                d = (d - 1)
            else:                 # 오른쪽이면
                d = (d + 1)
            if d >= 4: # 4방향 범위를 벗어나면 다시 균형 맞춤
                d -= 4
            if d < 0 :
                d += 4


## __main__ ##
N = int(input()) # 맵 크기
K = int(input()) # 사과 개수
apple = [list(map(int, input().split())) for _ in range(K)] # 사과 위치
L = int(input()) # 방향전환 횟수
info = {} # 방향전환 정보
for i in range(L):
    X, C = input().split()
    info[int(X)] = C

moves = [(0, 1), (1, 0), (0, -1), (-1, 0)] ## 우, 하, 좌, 상
MAP = [[0] * N for _ in range(N)]
for r, c in apple:
    MAP[r-1][c-1] = 'a'

print(solve())