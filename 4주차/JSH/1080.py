'''
01 뒤집기 -> 간단하게 전부 뒤집어 보는 방법 생각할 수 있음
-> 뒤집는 것은 A[i,j] != B[i,j]인 것만 뒤집을 거임.
-> 이때 , i+x, j+y 까지 다 뒤집음 (x: 0,1,2, y: 0,1,2) 

이 연산을 하면 기준칸(i, j)만 신경쓰면 된다. 
기준 칸은 이후의 연산에서 다시 선택되지 않는다. 하지만, 기준이 아니지만 뒤집어지는 부분들은 이후에 뒤집을 수 있다. (일부 제외)

이때, N-2열, N-1열과 M-2행, M-1행에서는 계산하지 않는다. 이 부분을 건들면, 이미 뒤집은 수들이 변하게 된다.
따라서, 이 부분들을 제외한 모든 칸들을 뒤집고, 결과를 판단하면 된다.

요약하자면, 기준이 되는 위치는 연산 후 다시 연산되지 않는다. 따라서, 모든 가능한 점들을 연산하고, 같다면 answer, 다르면 -1을 출력함
-> 연산(1): A[i,j] == B[i,j] -> pass
-> 연산(2): A[i,j] != B[i,j] -> A[i,j] 기준 3*3 뒤집기

'''
import sys

N, M = map(int, sys.stdin.readline().split())
A, B = [], []

for _ in range(N):
    A.append(list(map(int, list(map(str, sys.stdin.readline().strip('')))[:-1])))

for _ in range(N):
    B.append(list(map(int, list(map(str, sys.stdin.readline().strip('')))[:-1])))

answer = 0

for i in range(N-2):
    for j in range(M-2):
        if A[i][j] != B[i][j]:
            answer += 1
            for x in range(3):
                for y in range(3):
                    A[i+x][j+y] = 1 - A[i+x][j+y]
        else:
            continue
        
if A == B:
    print(answer)
else:
    print(-1)