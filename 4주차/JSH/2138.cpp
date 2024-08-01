/**
 * 
 * !!!!! scanf, cin 동시에 못 써!
 * 
 * 시작 부분을 누르고, 안누르고 두 경우로 나눠보기
 * 시작을 누른 상태에서 2번부터 시작 || 0번부터 시작
 * -> 체크하는 지점이 다르면 바꾸기
 * 
 * 000 -> 010
 * 000 > 110 > 001 > 010
 * 000 > 111 > 100 > 010
 * -> 순서는 상관 없어보임 -> 순차적으로 돌려보기
 * 
 */

#include <iostream>
using namespace std;

int N;
int init[100001], target[100001];
int copy_init[100001];

int answer = -1;
int tmp_ans = 0;

void remote(int bulb[], int index) {
    for(int i = index - 1; i <= index + 1; i++) {
        if (i >= 0 && i < N) bulb[i] = 1 - bulb[i];
    }
}

bool check(int bulb[], int target[]) {
    int ans = 0;

    for(int i=1; i < N; i++) {
        if(bulb[i-1] != target[i-1]) {
            remote(bulb, i);
            ans++;
        }
    }
    tmp_ans = ans;

    for(int i=0; i < N; i++) {
        if(bulb[i] != target[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);

    scanf("%d", &N);

    for(int i=0; i < N; i++) {
        scanf("%1d", &init[i]);
        copy_init[i] = init[i];
    }

    for(int i=0; i < N; i++) {
        scanf("%1d", &target[i]);
    }

    if(check(init, target)) {
        answer = tmp_ans;
    }

    remote(copy_init, 0);

    if(check(copy_init, target)) {
        tmp_ans++;
        if (answer == -1) answer = tmp_ans;
        else answer = min(answer, tmp_ans);
    }

    cout << answer << '\n';

    return 0;
}