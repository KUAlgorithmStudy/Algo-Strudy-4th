#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> stack;
vector<int> num;
int n, sel;

void arr(int s) {
	if (s <= 0) {
		for (int i = 0; i < sel; i++)
			cout << stack[i] << ' ';
		cout << "\n";

		return;
	}

	for (int i = 0; i < n; i++) {
		stack.push_back(num[i]);
		arr(s - 1);

		stack.pop_back();
		
	}
}	

int main() {
	cin >> n >> sel;

	num.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num.begin(), num.end());

	arr(sel);
}