/**
 * 버블 소트에서 스왑이 일어나지 않는 첫 번째 index 찾기
 * -> 가장 멀어진 index 찾기 (부호 고려해서 최댓값 찾기)
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, answer = -1000001;
pair<int, int> A[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A, A + N);

    for(int i=0; i < N; i++) {
        answer = max(answer, A[i].second - i);
    }
    
    cout << answer + 1;

    return 0;
}