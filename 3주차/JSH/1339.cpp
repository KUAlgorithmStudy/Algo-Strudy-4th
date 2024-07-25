/**
 * 두 가지 방법이 있음.
 * DFS로 백트래킹 돌리는거랑, 그리디로 걍 푸는거
 * 
 * 1. DFS: 길이가 맞으면, answer 갱신
 * -> 
 * 
 * 
 * 2. 그리디: 자릿수가 큰 알파벳부터 큰 수 넣기
 * -> 나중에 해보기
 * 
 */

#include <iostream>
using namespace std;

int N, length;
int answer = 0;
int alphabet[27];
bool visited[11], check[27];
string num[11];

void calculation() {
    int sum = 0;
    for(int i=0; i < N; i++) {
        int tmp = 1;
        for(int j = num[i].length() - 1; j >= 0; j--) {
            int index = num[i].at(j) - 'A';
            sum += tmp * alphabet[index];
            tmp *= 10;
        }
    }
    answer = max(answer, sum);
}

void solution(int index, int depth) {
    if(depth == length) {
        calculation();
        return;
    }

    while(!check[index]) index++;

    for(int i=0; i < 10; i++) {
        if(visited[i]) continue;
        alphabet[index] = i;
        visited[i] = true;
        solution(index + 1, depth + 1);
        visited[i] = false;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> num[i];
        for(int j=0; j < num[i].length(); j++) {
            int index = num[i].at(j) - 'A';
            check[index] = true;
        }
    }

    for(int i=0; i < 26; i++) {
        if(check[i]) length++;
    }

    solution(0, 0);
    cout << answer;

    return 0;
}