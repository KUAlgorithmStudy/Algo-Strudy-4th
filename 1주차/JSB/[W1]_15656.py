# W1 15656 N과 M (7)

def permutation(N, M, sequence):
    # 수열의 길이가 M에 도달하면 출력
    if len(sequence) == M:
        print(" ".join(map(str, sequence)))
        return

    # N번의 수를 시도
    for i in range(N):
        sequence.append(L[i])  # 현재 수를 수열에 추가
        permutation(N, M, sequence)  # 재귀 호출
        sequence.pop()  # 백트래킹: 마지막에 추가한 수 제거


## __main__ ##
N, M = map(int, input().split())
L = list(map(int, input().split()))
L.sort()

sequence = []
permutation(N, M, sequence)
