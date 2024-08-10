/**
 * 0 -> 3 || 0 > 1 > 2 > 3
 * 1 -> 5 || 1 > 2 > 4 > 5
 * 45->50 || 45 > 46 > 48 > 49 > 50
 * 
 * 각 숫자를 생각하지 말고, y - x의 값에 따라 생각해보기
 * -> 시점, 종점은 1씩 이동. 최적의 해: 절반까지 1씩 증가 (k/2 * (k/2+1))/2, k = y-x
 * 1 2 1 -> 4 (3)
 * 1 2 3 2 1 -> 9 (5)
 * 1 2 3 4 3 2 1 -> 16 (7) -> N^2 (2N-1)
 * 
 * X = N^2 + t -> (2N-1) + count(t)
 * 13 = 3^2 + 4, 5 + (4/3 up) -> 7
 * 11 = 3^2 + 2, 5 + 1 -> 6
 * 
 * if t > N -> +(t/N 올림수)
 * else + 1
 * 
 */
#include <iostream>
#include <cmath>
using namespace std;

double T, x, y;
double answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> x >> y;
        double interval = y - x;
        answer = 0;

        double cnt = 0;
        while(cnt * cnt <= interval) cnt++;
        cnt--;
        answer += 2*cnt - 1;

        double rest = interval - cnt*cnt;
        answer += ceil(rest / cnt);

        cout << answer << '\n';
    }

    return 0;
}