/**
 * 이동 방향 3가지. 우선순위를 줄거임. [우상] > [우] > [우하]
 * 가장 위에서[0,0]부터 아래 빵집에서 탐색 시작. 최대한 우선순위를 높게 경로 선택
 * 가능하면 답, 아니면 나가리
 * 
 * 아이디어
 * 최대한 파이프를 적게 써보자. -> 영향을 미치는 것은 "시작점, 도착점 사이의 y좌표 거리"
 * -> x좌표 거리는 C로 일정함. 우선순위를 고려하여 경로를 탐색해야 함.
 * 
 * 그렇다면 반례가 존재하지 않을까?
 * 지도의 좌상단에서 우하단으로 연결할 수 있을 때, 연결하지 않고 최적해를 찾을 수 있을까...
 * -> 1에서 선택하지 않았을 때, 다른 곳에서 더 많은 해가 나오는가?
 * -> ㄴㄴ. 1에서 다른 곳으로 연결할 수 없다. -> 다른 곳에서 탐색해도 거기는 못간다.
 */

#include <iostream>
using namespace std;

int R, C;
int answer = 0;
char graph[10001][501];
bool visited[10001][501];

int dr[3] = {-1, 0, 1};
int dc[3] = {1, 1, 1};

bool dfs(int r, int c) {
    if(c == C-1) return true;

    for(int i=0; i < 3; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
        if (visited[nr][nc] || graph[nr][nc] == 'x') continue;

        visited[nr][nc] = true;
        if(dfs(nr, nc)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for(int r=0; r < R; r++)
        for(int c=0; c < C; c++)
            cin >> graph[r][c];
    
    for(int r=0; r < R; r++)
        answer += dfs(r, 0);

    cout << answer;

    return 0;
}