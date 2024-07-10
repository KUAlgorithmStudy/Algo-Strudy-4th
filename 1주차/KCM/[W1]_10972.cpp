#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	vector<int> v;
	bool last;
	
	cin >> n;

	v.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	last = !(next_permutation(v.begin(), v.end()));

	if (last) {
		cout << "-1";
	}
	else {
		for (int i = 0; i < n; i++)
			cout << v[i] << ' ';
	}
}