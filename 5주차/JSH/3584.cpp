/**
 * 최소 공통 조상: Lowest Common Ancestor (LCA Algorithm)
 * 
 * 그림에서 11, 15의 LCA는 4임.
 * 
 * 11과 15에서 각각 루트로 가능 경로
 * 11 -> 10 -> 4 -> 8
 * 15 -> 6  -> 4 -> 8
 * 
 * -> 4, 8이 공통 조상이고, LCA는 4임. 
 * -> 두 노드의 부모배열을 만들고, 공통된 조상 찾기
 * -> 1차원 배열, index로 관리해보기.
 * 부모에서 시작하면서 A, B로 갈라진다. -> 달라지는 부분이 있다면 그 직전이 LCA
 * 
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, N, A, B, node1, node2;
int tree[10002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--) {
        memset(tree, 0, sizeof(tree));
        vector<int> node1_parent, node2_parent;

        cin >> N;
        for(int i=0; i < N-1; i++) {
            cin >> A >> B;
            tree[B] = A;
        }
        cin >> node1 >> node2;

        while(node1 != 0) {
            node1_parent.push_back(node1);
            node1 = tree[node1];
        }

        while(node2 != 0) {
            node2_parent.push_back(node2);
            node2 = tree[node2];
        }

        int index_1 = node1_parent.size() - 1;
        int index_2 = node2_parent.size() - 1;

        while(node1_parent[index_1] == node2_parent[index_2]) {
            index_1--;
            index_2--;
        }

        cout << node1_parent[index_1 + 1] << '\n';
    }

    return 0;
}