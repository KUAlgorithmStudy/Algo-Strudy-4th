'''
Solve (1)

Example: 1 4 3 2
1. 뒤에서부터 체크, 뒷값이 앞값보다 큰거 찾기
(1 4) 3 2

2. 뒤에서부터 비교, 체크의 앞 값보다 큰 값이 있다면 교체
(2 4) 3 1

3. 교체한 값 뒤부터 정렬

result -> 2 1 3 4

얼핏 코드만 보면 복잡도가 되게 커보인다. 하지만, 조건문에 들어가게 되면 이전의 반복을 실행하지 않게 되므로 실제 복잡도는 크지 않다.
이게 가능할까 했지만 생각보다 계산량이 많지 않다는 것을 알 수 있었다.
-> O(NlogN)으로 통과함. 그런데 2번 풀이가 더 좋다.
'''

# import sys

# N = int(input())
# current_permutaiton = list(map(int, sys.stdin.readline().split()))

# is_last = True
# answer = []

# for i in range(N-1, 0, -1):
#     if current_permutaiton[i-1] < current_permutaiton[i]:
#         is_last = False
#         tmp_index = i-1

#         for j in range(N-1, 0, -1):
#             if current_permutaiton[tmp_index] < current_permutaiton[j]:
#                 current_permutaiton[tmp_index], current_permutaiton[j] = current_permutaiton[j], current_permutaiton[tmp_index]

#                 answer = current_permutaiton[:i] + sorted(current_permutaiton[i:])
#                 break
#         break

# if is_last:
#     print(-1)
# else:
#     print(' '.join(map(str, answer)))
    

'''
Solve(2) 

O(N) 풀이도 있다. 가장 최적화된 풀이가 이거임.
1번 풀이와 거의 비슷하다. 여기서는 정렬을 하지 않고, 뒷부분을 뒤집는걸로 끝낸다. 나머지는 동일

이게 어떻게 가능한가?

1번의 알고리즘을 살펴보자

1. 뒤에서부터 체크, 뒷값이 앞값보다 큰거 찾기
2. 뒤에서부터 비교, 체크의 앞 값보다 큰 값이 있다면 교체
3. 교체한 값 뒤부터 정렬

1 4 3 2를 예시로 하자

1. 여기서는 (1 4)가 걸림. 나머지는 4 3 2임. 즉, 이미 정렬이 된 상태 (역순)
2. 값 바꾸면 (2 4 3 1) -> 뒤집어지는 수는 가장 뒷부분에서 가장 작은 수라는 것이 자명함. (바꾸는 수의 뒷 수는 뒷그룹에서 가장 큰 수)
3. 이제 뒷그룹을 조정해서 가장 작은 값을 만들어야 함. (값을 교체한 순간, 기존의 정답보다 커짐. 순열은 사전순으로 증가하기 때문에 기존 수보다 큰 수 중에서 가장 작은 값을 찾아야 함)
-> 그룸은 [2] [4 3 1]인데, 기존의 4 3이고, 가장 작은 수가 맨 뒤로 감. -> 역순으로 만들면 [1 3 4]
-> 정렬을 할 필요가 없다. 뒤집기만 하면 끝

2 3 4 1
-> 2 (3 4) 1
-> 2 4 3 1
-> [2 4] [3 1]
-> [2 4 1 3]
'''

def next_permutation(current_permutation):
    N = len(current_permutation)
    
    for i in range(N-1, 0, -1):
        if current_permutation[i-1] < current_permutation[i]:
            break
    else:
        return -1
    
    for j in range(N-1, i-1, -1):
        if current_permutation[i-1] < current_permutation[j]:
            current_permutation[i-1], current_permutation[j] = current_permutation[j], current_permutation[i-1]
            break
    
    current_permutation[i:] = reversed(current_permutation[i:])
    
    return current_permutation

N = int(input())
current_permutation = list(map(int, input().split()))

result = next_permutation(current_permutation)

if result == -1:
    print(-1)
else:
    print(' '.join(map(str, result)))
