#include <iostream>
#include <vector>
using namespace std;

class Bakery {
	int dy[3] = { -1, 0, 1 };
	vector<vector<bool>> arr;
	int C, R;
	bool dfs(int, int);
public:
	Bakery(int r = 0, int c = 0) {
		R = r;
		C = c;
		
		vector<bool> v(C, false);
		arr.assign(R, v);
	}
	void inputArr();
	int maxPipe();
};

void Bakery::inputArr() {
	string s;

	for (int i = 0; i < R; i++) {
		cin >> s;

		for (int j = 0; j < C; j++) {
			if (s[j] == 'x')
				arr[i][j] = true;
		}
	}
}

bool Bakery::dfs(int y, int x) {
	arr[y][x] = true;

	if (x == C - 1)
		return true;

	for (int i = 0; i < 3; i++) {
		if (y + dy[i] >= 0 && y + dy[i] < R && !arr[y + dy[i]][x + 1]) {
			if (dfs(y + dy[i], x + 1))
				return true;

		}
	}

	return false;
}

int Bakery::maxPipe() {
	int cnt = 0;

	for (int i = 0; i < R; i++) {
		if (dfs(i, 0))
			cnt++;
	}

	return cnt;
}

int main() {
	int R, C;

	cin >> R >> C;

	Bakery b(R, C);
	b.inputArr();

	cout << b.maxPipe();
}