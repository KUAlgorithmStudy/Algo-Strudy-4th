#include <iostream>
#include <vector>
using namespace std;

class matrix {
	vector<vector<bool>> mat;  // 원소가 같으면 true, 다르면 false
	int h, w;
	int numOfDiffer = 0;
	void flip(int, int);
public:
	matrix(int n = 0, int m = 0) {
		h = n;
		w = m;
		vector<bool> v(w, false);
		mat.assign(h, v);
	}
	void inputMatrix();
	int numOfCalc();
};

void matrix::inputMatrix() {
	string s;

	for (int i = 0; i < h; i++) {
		cin >> s;

		for (int j = 0; j < w; j++) {
			mat[i][j] = bool(s[j] - '0');
		}
	}

	for (int i = 0; i < h; i++) {
		cin >> s;

		for (int j = 0; j < w; j++) {
			mat[i][j] = (mat[i][j] == bool(s[j] - '0'));
			if (!mat[i][j])
				numOfDiffer++;
		}
	}
}

int matrix::numOfCalc() {
	if (h < 3 || w < 3) {
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (!mat[i][j])
					return -1;
	}
	
	int cnt = 0;

	for (int i = 0; i < h - 2; i++) {
		for (int j = 0; j < w - 2; j++) {
			if (!mat[i][j]) {
				flip(i, j);
				cnt++;
			}
		}
	}

	if (numOfDiffer > 0)
		return -1;

	return cnt;
}

void matrix::flip(int y, int x) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			mat[i][j] = !mat[i][j];
			if (mat[i][j]) {
				numOfDiffer--;
			}
			else {
				numOfDiffer++;
			}
		}
	}
}

int main() {
	int N, M;

	cin >> N >> M;

	matrix m(N, M);
	m.inputMatrix();

	cout << m.numOfCalc();
}