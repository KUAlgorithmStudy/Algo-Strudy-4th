/**
 * 문제 요약부터 해야겠다. 글이 이상함..
 * 
 * 1. 고속도로에 N개의 센서를 설치함.
 * 2. 이때 최대 K개의 집중국을 지을거임.
 * 2-1. 집중국에서는 센서 수신 영역을 조절 가능
 * 2-2. 모든 센서는 적어도 하나의 집중국과 연결
 * 3. 각 집중국의 수신 가능 영역의 최소 길이 구하기
 * 
 * 음수 좌표 가능. 영역의 길이는 정수
 * 
 * 6개의 센서, 2개의 집중국이 있을 때.
 * 1 3 6(6) 7 9 라는 센서가 주어짐.
 * 1, 7에 두면
 * 0 2 | 1 0 2 -> 5
 * 
 * 2 6 7 8 10 12 14 15 18 20 | 5개 집중국
 * 2, 7, 11, 14, 19에 두면
 * 0 | 1 0 1 | 1 1 | 0 1 | 1 1 -> 7
 * 
 * K개의 집중국을 사용하면 K-1개의 덩어리가 생김.
 * -> 각 센서사이의 거리 중 큰 것들에 집중국 박으면 됨.
 * 
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int answer = 0;
int road[10001];
int interval[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin >> K;

    for(int i=0; i < N; i++)
        cin >> road[i];

    sort(road, road + N);

    for(int i=0; i < N-1; i++) {
        interval[i] = road[i+1] - road[i];
    }

    sort(interval, interval + (N - 1), greater<int>());

    for(int i=0; i < K-1; i++) {
        interval[i] = 0;
    }

    for(int i=0; i < N-1; i++) {
        answer += interval[i];
    }

    cout << answer;

    return 0;
}