/**
 * 두 노드는 항상 leaf임. leaf가 아니라고 가정.
 * -> 해당 노드 아래 다른 노드들이 있음. 현재의 dist + 남은 노드의 길이 > dist
 * -> 따라서, 항상 leaf - leaf가 되어야 함.
 * 
 * 원 내부에 여러 점이 있고, 두 점은 원의 지름을 이룬다고 가정한다.
 * 임의의 점을 골랐을 때, 이 점에서 가장 멀리 떨어진 점은 원의 지름을 이루는 점 중 하나이다.
 * 따라서, 임의의 정점에서 dfs를 통해 가장 멀리 떨어진 점을 찾고, 그 점에서 dfs를 돌리면 지름이 나온다.
 * 
 * 
 * root -> 1 -> 여기서 dfs 돌리기
 */

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

int n, src, dest, cost;
int max_length = 0;
int max_node;
vector<pair<int, int>> tree[10002];
bool visited[10002] = {false,};

void dfs(int current, int depth) {
    if(visited[current]) return;

    visited[current] = true;

    if(max_length < depth) {
        max_length = depth;
        max_node = current;
    }

    for(int i=0; i < tree[current].size(); i++) {
        dfs(tree[current][i].first, depth + tree[current][i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n - 1; i++) {
        cin >> src >> dest >> cost;
        tree[src].push_back({dest, cost});
        tree[dest].push_back({src, cost});
    }

    dfs(1, 0);
    
    max_length = 0;
    memset(visited, false, sizeof(visited));

    dfs(max_node, 0);
    cout << max_length;

    return 0;
}