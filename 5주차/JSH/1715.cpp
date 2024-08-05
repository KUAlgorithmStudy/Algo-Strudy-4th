/**
 * 10 20 30 40 50
 * -> 10 + 20, 30, 40, 50 -> ans = 30 | 30 30 40 50
 * -> 30+30, 40, 50 -> ans = 90 | 60 50 40
 * -> 40 + 50, 60 -> ans = 180 | 90 60
 * -> 60 + 90 -> ans = 330 | 150
 * 
 * 3 3 3 3
 * 3 + 3, 3, 3 -> ans = 6, | 6 3 3
 * 6, 3 + 3 -> ans = 12, | 6 6
 * 6+6 -> ans = 24, | 12
 * 
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long N, tmp;
long long answer = 0;
priority_queue<long long, vector<long long>, greater<long long>> card;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> tmp;
        card.push(tmp);
    }

    for(int i=0; i < N-1; i++) {
        int value = 0;
        value += card.top();
        card.pop();
        
        value += card.top();
        card.pop();
        
        card.push(value);
        answer += value;
    }
    
    if (N == 1) answer = 0;
    cout << answer;

    return 0;
}