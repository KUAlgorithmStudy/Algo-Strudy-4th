#include <iostream>
#include <vector>
using namespace std;

vector<int> stack;
vector<bool> is_selected;
int n, sel;

void arr(int s) {
	if (s <= 0) {
		for (int i = 0; i < sel; i++)
			cout << stack[i] << ' ';
		cout << "\n";
		
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!is_selected[i]) {
			is_selected[i] = true;
			stack.push_back(i);
			arr(s - 1);

			is_selected[i] = false;
			stack.pop_back();
		}
	}
}

int main() {
	cin >> n >> sel;

	is_selected.assign(n + 1, false);

	arr(sel);
}