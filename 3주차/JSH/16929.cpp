/**
 * 각 색깔별로 좌표 dfs 돌려서 사이클인지 판단
 * 하나라도 사이클이 존재하면 yes 아니면 no
 * 
 * 사이클이 존재하려면 시작점과 종점이 일치
 * -> 첫 시작에서는 visited 처리하지 않음
 * 
 */

#include <iostream>
using namespace std;

int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char game[51][51];
bool visited[51][51];
bool is_cycle = false;
int start_x, start_y;

void search_cycle(char start_point, int cur_x, int cur_y, int cnt) {
    if (cnt >= 3 && cur_x == start_x && cur_y == start_y) {
        is_cycle = true;
        return;
    }

    for(int i=0; i < 4; i++) {
        int nx = cur_x + dx[i];
        int ny = cur_y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
       
        if(!visited[nx][ny] && game[nx][ny] == start_point) {
            visited[nx][ny] = true;
            search_cycle(game[nx][ny], nx, ny, cnt+1);
            visited[nx][ny] = false;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i < N; i++)
        for(int j=0; j < M; j++) {
            cin >> game[i][j];
        }

    for(int i=0; i < N; i++) {
        for(int j=0; j < M; j++) {
            if(!visited[i][j]) {

                for(int i=0; i < N; i++)
                    for(int j=0; j < M; j++)
                        visited[i][j] = false;

                start_x = i; start_y = j;
                search_cycle(game[i][j], i, j, 0);

                if(is_cycle) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
            
    cout << "No";

    return 0;
}