/**
 * N명이 있을 때, N/2명이 두 팀을 이룸
 * -> Sij = i번사람과 j번 사람의 능력치
 * -> 팀 능력치는 Sij의 합 [Sij, Sji를 합함]
 * 두 팀의 전력 차이를 최소로 할거임.
 * 
 * 백트래킹 N/2번까지 돌리고, 나머지 합 -> 두 합의 차이를 갱신
 * 
 */

#include <iostream>
using namespace std;

int N;
int S[21][21];
bool visited[21];
int answer = 10000;

void calculate() {
    int score_A = 0, score_B = 0;

    for(int i=0; i < N; i++) {
        for(int j=0; j < N; j++) {
            if(visited[i] && visited[j]) score_A += S[i][j];
            else if (!visited[i] && !visited[j]) score_B += S[i][j];
        }
    }
    int score = abs(score_A - score_B);
    if (score < answer) answer = score;
}

void solution(int count, int index) {
    if (count == N/2) {
        calculate();
        return;
    }

    for(int i = index; i < N; i++) {
        visited[i] = true;
        solution(count + 1, i + 1);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            cin >> S[i][j];
    
    solution(0, 0);

    cout << answer;

    return 0;
}