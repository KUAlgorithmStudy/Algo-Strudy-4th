#include <iostream>
using namespace std;

int main() {
	int T, x, y;
	long long n, d;
	int min;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> x >> y;

		d = y - x;

		n = 1;
		while (d > n * (n + 1))
			n++;

		min = n * 2;
		if (d <= n * n)
			min--;

		cout << min << "\n";
	}
}