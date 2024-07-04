import sys

N, M = map(int, sys.stdin.readline().split())
answer_list = []

def dfs():
    if len(answer_list) == M:
        print(' '.join(map(str, answer_list)))
        return
    
    for i in range(1, N+1):
        if i not in answer_list:
            answer_list.append(i)
            dfs()
            answer_list.pop()
dfs()

'''
간단한 풀이 -> 출제의도는 이게 아니야!

import itertools
import sys

N, M = map(int, sys.stdin.readline().split())
num_list = [i for i in range(1, N+1)]

answer_list = itertools.permutations(num_list, M)

for i in answer_list:
    for j in i:
        print(j, end = ' ')
    print()
'''