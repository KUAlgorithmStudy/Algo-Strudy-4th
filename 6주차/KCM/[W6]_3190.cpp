#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Dummy {
	pair <int, int> currLoc = { 1, 1 };
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	int dir = 0;
	queue <pair <int, char>> changeInfo;
	vector<vector<int>> board;
	int boardSize;
	void dirChange(char);
public:
	Dummy(int n = 2) {
		boardSize = n;
		
		vector<int> v(n + 2, 0);
		v[0] = -1;
		v[n + 1] = -1;
		board.assign(n + 2, v);

		v.assign(n + 2, -1);
		board[0] = v;
		board[n + 1] = v;
	}
	void inputApple(int);
	void inputDir(int);
	void start();
};

void Dummy::inputApple(int k) {
	int y, x;

	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		board[y][x] = 2;
	}
}

void Dummy::inputDir(int l) {
	int x;
	char ch;

	for (int i = 0; i < l; i++) {
		cin >> x >> ch;
		changeInfo.push({ x, ch });
	}
}

void Dummy::dirChange(char ch) {
	if (ch == 'L') {
		dir = (dir + 1) % 4;
	}
	else if (ch == 'D') {
		dir = (dir + 3) % 4;
	}
}

void Dummy::start() {
	queue <pair <int, int>> snake;
	int cnt = 0;
	int locInfo;
	pair <int, char> change = changeInfo.front();
	changeInfo.pop();

	board[1][1] = 1;
	snake.push({ 1, 1 });

	while (true) {
		cnt++;

		currLoc = { currLoc.first + dy[dir], currLoc.second + dx[dir] };
		snake.push({ currLoc.first, currLoc.second });
		locInfo = board[currLoc.first][currLoc.second];

		if (locInfo == -1 || locInfo == 1) {
			break;
		}
		else {
			board[currLoc.first][currLoc.second] = 1;

			if (locInfo == 0) {
				board[snake.front().first][snake.front().second] = 0;
				snake.pop();
			}
		}

		if (cnt == change.first) {
			dirChange(change.second);

			if (!changeInfo.empty()) {
				change = changeInfo.front();
				changeInfo.pop();
			}
		}
	}

	cout << cnt;
}

int main() {
	int N, K, L;

	cin >> N;

	Dummy dummy(N);

	cin >> K;
	dummy.inputApple(K);

	cin >> L;
	dummy.inputDir(L);

	dummy.start();
}