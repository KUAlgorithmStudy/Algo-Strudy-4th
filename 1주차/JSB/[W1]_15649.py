# W1 15649 N과 M (1)

def permutation(N, M, sequence, used):
    # 수열의 길이가 M에 도달하면 출력
    if len(sequence) == M:
        print(" ".join(map(str, sequence)))
        return

    # 1부터 N까지의 수를 시도
    for i in range(1, N + 1):
        # 이미 사용한 수인지 확인
        if not used[i]:
            sequence.append(i)  # 현재 수를 수열에 추가
            used[i] = True  # 현재 수를 사용했음을 표시
            permutation(N, M, sequence, used)  # 재귀 호출
            sequence.pop()  # 백트래킹: 마지막에 추가한 수 제거
            used[i] = False  # 백트래킹: 현재 수 사용 해제


## __main__ ##
N, M = map(int, input().split())
sequence = []
used = [False] * (N + 1)  # 1부터 N까지의 숫자 사용 여부를 나타내는 리스트
permutation(N, M, sequence, used)
