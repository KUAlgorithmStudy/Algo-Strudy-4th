# W7: 9935 문자열 폭발

content = input()
bomb = input()

stack = []

for char in content:
    stack.append(char)

    if stack[-len(bomb):] == list(bomb):
        for _ in range(len(bomb)):  # 폭발 문자열이 있으면 해당 부분 제거
            stack.pop()

# 결과 출력
result = ''.join(stack)
if result:
    print(result)
else:
    print('FRULA')
