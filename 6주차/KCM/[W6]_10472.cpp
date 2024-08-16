#include <iostream>
#include <vector>
using namespace std;

class CrossFlip {
	vector<vector<bool>> board;
	vector<vector<bool>> dest;
	void flip(int, int);
	bool isEqual();
	int bx[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };
	int by[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
	int cnt;
	bool dfs(int);
public:
	void clearBoard();
	void inputDest();
	int changeBoard();
};

void CrossFlip::clearBoard() {
	vector<bool> v(3, false);
	board.assign(3, v);
	dest.assign(3, v);
}

void CrossFlip::inputDest() {
	string s;

	for (int i = 0; i < 3; i++) {
		cin >> s;

		for (int j = 0; j < 3; j++) {
			if (s[j] == '*')
				dest[i][j] = true;
		}
	}
}

void CrossFlip::flip(int y, int x) {
	board[y][x] = !board[y][x];
	if (y - 1 >= 0)
		board[y - 1][x] = !board[y - 1][x];
	if (y + 1 < 3)
		board[y + 1][x] = !board[y + 1][x];
	if (x - 1 >= 0)
		board[y][x - 1] = !board[y][x - 1];
	if (x + 1 < 3)
		board[y][x + 1] = !board[y][x + 1];
}

bool CrossFlip::isEqual() {
	return board == dest;
}

bool CrossFlip::dfs(int k) {
	cnt++;
	flip(by[k], bx[k]);

	if (isEqual())
		return true;

	for (int i = k + 1; i < 9; i++) {
		if (dfs(i))
			return true;
	}

	flip(by[k], bx[k]);
	cnt--;
	return false;
}

int CrossFlip::changeBoard() {
	cnt = 0;

	for (int i = 0; i < 9; i++) {
		if (dfs(i))
			return cnt;
	}

	return cnt;
}

int main() {
	int T;
	CrossFlip cf;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cf.clearBoard();
		cf.inputDest();

		cout << cf.changeBoard() << "\n";
	}
}