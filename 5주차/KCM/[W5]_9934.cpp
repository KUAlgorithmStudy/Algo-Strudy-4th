#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int K, n;

	cin >> K;

	n = pow(2, K) - 1;
	vector<int> building(n, 0);

	for (int i = 0; i < n; i++)
		cin >> building[i];


	for (int i = 0; i < K; i++) {
		for (int j = pow(2, K - i - 1) - 1; j < n; j += pow(2, K - i)) {
			cout << building[j] << ' ';
		}
		cout << "\n";
	}
}