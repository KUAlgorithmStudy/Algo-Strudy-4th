/**
 * Root에서 시작. 0 -> 9까지 각 층에서 순서대로 탐색
 * -> 가능한 경우의 수 중 가장 먼저 나온거 -> 최소
 * -> 가능한 경우의 수 중 가장 나중에 나온거 -> 최대
 * -> 백트래킹으로 구현하면 됨, 가장 작은건 먼저 구해지고, 큰걸 계속 갱신하면 됨. 
 * 
 * 2 < >
 * 시작: 0 -> 1 (x), 0 -> 2 -> 1 (o)
 * ...
 * 8 -> 9 -> 7 (o), 9 -> 8 (x)
 * -> 021, 897
 * 
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int k;
vector<char> order;
string max_number = "", min_number = "9999999999";
bool visited[11];

void solution(string s) {
    if (s.size() == k + 1) {
        max_number = max(max_number, s);
        min_number = min(min_number, s);

        return;
    }

    for(int i=0; i < 10; i++) {
        if (visited[i]) continue;
        if (order[s.size() - 1] == '>') {
            if (s.back() - '0' < i) continue;
        }
        if (order[s.size() - 1] == '<') {
            if (s.back() - '0' > i) continue;
        }

        visited[i] = true;
        s.push_back(i + '0');

        // cout << s << ' ' << max_number << ' ' << min_number << endl;

        solution(s);
        s.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    order.resize(k);

    for(int i=0; i < k; i++)
        cin >> order[i];

    string s = "";

    for(int i=0; i < 10; i++) {
        visited[i] = true;
        s.push_back(i + '0');
        solution(s);
        s.pop_back();
        visited[i] = false;
    }

    cout << max_number << '\n';
    cout << min_number;

    return 0;
}