# W1 10972 다음 순열

N = int(input())
L = list(map(int, input().split()))

for i in range(N-1, 0, -1):  # 맨 뒤 값부터 시작
    if L[i-1] < L[i]:
        for j in range(N-1, 0, -1):  # 다시 맨 뒤 값부터 큰 값찾기
            if L[i-1] < L[j]:
                L[i-1], L[j] = L[j], L[i-1]  # 둘 값을 swap
                L = L[:i] + sorted(L[i:])
                for k in L:
                    print(k, end=' ')
                exit()
print(-1)
