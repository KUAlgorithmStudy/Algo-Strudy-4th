#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int N;
char root, l_child, r_child;
vector<pair<int, int>> tree(26);

void preorder(int N) {
    if (N == -1) return;
    cout << (char)(N + 'A');
    preorder(tree[N].first);
    preorder(tree[N].second);
}

void inorder(int N) {
    if (N == -1) return;
    inorder(tree[N].first);
    cout << (char)(N + 'A');
    inorder(tree[N].second);
}

void postorder(int N) {
    if (N == -1) return;
    postorder(tree[N].first);
    postorder(tree[N].second);
    cout << (char)(N + 'A');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> root >> l_child >> r_child;

        root -= 'A';

        if (l_child == '.') {
            tree[root].first = -1;
        } else {
            tree[root].first = l_child - 'A';
        }

        if (r_child == '.') {
            tree[root].second = -1;
        } else {
            tree[root].second = r_child - 'A';
        }
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);

    return 0;
}