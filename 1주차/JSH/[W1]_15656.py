import sys

N, M = map(int, sys.stdin.readline().split())
num_list = list(map(int, sys.stdin.readline().split()))
answer_list = []

def dfs():
    if len(answer_list) == M:
        print(' '.join(map(str, answer_list)))
        return
    
    for i in num_list:        
        answer_list.append(i)
        dfs()
        answer_list.pop()

num_list.sort()
dfs()