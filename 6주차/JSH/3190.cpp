/**
 * 뱀이 매 초 이동
 * -> 머리를 다음칸으로 이동
 * -> 이동한 칸에 사과가 있으면 사과 없어지고 몸길이 늘어남
 * -> 사과 없으면 몸길이 늘어나지 않음. 따라서, 꼬리도 움직임
 * 
 * 시작 길이: 1
 * 시작 위치: 좌상단, 우측을 향함
 * 자신의 몸이나 벽에 박으면 끝
 * 
 * N*N 보드 위에 K 개의 사과가 있음. 각 사과의 위치가 주어진다.
 * deque으로 시작, 끝 지점 관리
 * 
 */

#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int N, K, L, X, r, c;
char C;

int board[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cmd_time[101];
char cmd[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(board, 0, sizeof(board));

    deque<pair<int, int>> snake;
    snake.push_back({1, 1});
    board[1][1] = -1;

    cin >> N;
    cin >> K;

    for(int i=0; i < K; i++) {
        cin >> r >> c;
        board[r][c] = 1;
    }

    cin >> L;

    for(int i=0; i < L; i++) {
        cin >> cmd_time[i] >> cmd[i];
    }

    int cmd_idx = 0; 
    int direction = 0; 
    int timer = 0;

    while(true) {
        timer++;

        int new_x = snake.front().first + dx[direction];
        int new_y = snake.front().second + dy[direction];

        if (new_x < 1 || new_x > N || new_y < 1 || new_y > N || board[new_x][new_y] == -1) {
            cout << timer;
            break;
        }

        if (board[new_x][new_y] == 1) {
            board[new_x][new_y] = -1;
            snake.push_front({new_x, new_y});
        } 
        else {
            board[new_x][new_y] = -1;
            snake.push_front({new_x, new_y});
            pair<int, int> tail = snake.back();
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }

        if(cmd_time[cmd_idx] == timer) {
            if (cmd[cmd_idx] == 'L') {
                direction = (direction + 3) % 4;
            }
            else if (cmd[cmd_idx] == 'D') {
                direction = (direction + 1) % 4;
            }
            cmd_idx++;
        }
    }

    return 0;
}
