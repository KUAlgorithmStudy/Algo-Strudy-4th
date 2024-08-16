#include <iostream>
using namespace std;

int N, M;
int A[1000001], B[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i < N; i++)
        cin >> A[i];
    for(int i=0; i < M; i++)
        cin >> B[i];

    int idx_A = 0, idx_B = 0;
    for(int i=0; i < N + M; i++) {
        if (A[idx_A] <= B[idx_B]) {
            cout << A[idx_A] << ' ';
            idx_A++;
        }
        else {
            cout << B[idx_B] << ' ';
            idx_B++;
        }

        if (idx_A == N) {
            for(i = idx_B; i < M; i++)
                cout << B[i] << ' ';
            break;
        }
        if (idx_B == M) {
            for(i = idx_A; i < N; i++)
                cout << A[i] << ' ';
            break;
        }
    }

    return 0;
}