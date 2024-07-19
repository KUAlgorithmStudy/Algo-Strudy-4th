#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class NumJmp {
	vector<vector<char>> numPlate;
	unordered_set<string> numbers;
	string numStr;
	void dfs(pair<int, int>);
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
public:
	NumJmp() {
		vector<char> v(5, 0);
		numPlate.assign(5, v);
	}
	void input();
	int countNum();
};

void NumJmp::input() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> numPlate[i][j];
}

void NumJmp::dfs(pair<int, int> crd) {
	int x, y;

	for (int i = 0; i < 4; i++) {
		x = crd.first + dx[i];
		y = crd.second + dy[i];

		if (x >= 0 && y >= 0 && x < 5 && y < 5) {
			numStr += numPlate[y][x];

			if (numStr.length() < 6) {
				dfs({ x, y });
			}
			else {
				numbers.insert(numStr);
			}

			numStr.erase(numStr.length() - 1, 1);
		}
	}
}

int NumJmp::countNum() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			numStr = numPlate[i][j];
			dfs({ j, i });
		}
	}

	return numbers.size();
}

int main() {
	NumJmp nj;

	nj.input();

	cout << nj.countNum();
}