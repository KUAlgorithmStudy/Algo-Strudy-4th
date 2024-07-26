# -*- coding: utf-8 -*-
"""[W3]_2529.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1IXLYqj-zbLA0o4x_yPeCIj4aj6Bf_T4_
"""

# W3 2529 부등호

def check(a, b, op):
    if op == '<' and a > b:
        return False
    if op == '>' and a < b:
        return False
    return True

def dfs(cnt, num):
    if cnt == k+1:
        answer.append(num)
        return

    for i in range(10):
        if visited[i]:
            continue
        if cnt == 0 or check(num[cnt-1], str(i), signs[cnt-1]):
            visited[i] = 1
            dfs(cnt+1, num+str(i))
            visited[i] = 0


## __main__ ##
k = int(input())
signs = list(input().split())

visited = [0]*10
answer = []
dfs(0, '')
answer.sort()

print(answer[-1])
print(answer[0])
