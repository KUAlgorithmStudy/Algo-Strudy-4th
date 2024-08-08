/** Solution 1.
 * 완전 이진트리의 inorder traverse 결과를 가지고, 원본 트리를 추적하는 문제
 *       3
 *   6       2
 * 1   4   5   7   -> inorder: 1 6 4 3 5 2 7
 * 
 * -> index: 1 - 8이라고 하면, 홀수: leaf
 * -> index % 4 == 0 -> root
 * -> index % 2 == 0 -> level 2.
 * 
 * K가 커지면 안된다.. ㄲㅂ
 */

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <utility>
// using namespace std;

// int K;
// vector<pair<int, int>> binary_tree;

// bool compare(pair<int, int> a, pair<int, int> b) {
//     return a.second > b.second;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> K;
//     binary_tree.resize(1025);


//     for(int i=1; i < (1 << K); i++) {
//         cin >> binary_tree[i].first;

//         for(int j = 0; j < K; j++) {
//             if (i % (1 << (K - j - 1)) == 0) {
//                 binary_tree[i].second = K - j;
//                 break;
//             }
//         }
//     }

//     sort(binary_tree.begin() + 1, binary_tree.end(), compare);

//     for(int i=1; i < (1<<K); i++) {
//         cout << binary_tree[i].first << ' ';
        
//         if ((i & (i+1)) == 0) cout << '\n';
//     }    

//     return 0;
// }

/** Solution 2.
 * Sol1과 비슷한 아이디어로 접근. 재귀 사용해서 값 찾기
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

int K;
vector<int> tree[10];
int inorder[1025];

void solution(int depth, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    tree[depth].push_back(inorder[mid]);
    solution(depth + 1, left, mid);
    solution(depth + 1, mid + 1, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;
    for(int i=0; i < (1 << K) - 1; i++) 
        cin >> inorder[i];

    solution(0, 0, (1 << K) - 1);

    for(int i=0; i < K; i++) {
        for (auto order : tree[i]) {
            cout << order << ' ';
        }
        cout << '\n';
    }
 
    return 0;
}