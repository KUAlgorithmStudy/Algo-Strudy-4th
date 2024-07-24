/**
 * 입력된 숫자 순서대로 가능한 모든 연산을 백트래킹으로 돌려보기
 * 
 * 백트래킹을 설계하는 문제의 흐름
 * 1. 재귀 함수 설정
 * 1-1. 종료 조건 설정
 * 1-2. 하나 더하거나 빼고, 재귀 돌리고, 돌아가고 난 뒤에 원상복구[끝 봤으면 되돌아가야함]
 */

#include <iostream>
using namespace std;

int N;
int num_list[12], oper_list[5];
int max_answer = -1000000001, min_answer = 1000000001;

void solution(int result, int index) {
    if (index == N) {
        if (result > max_answer) max_answer = result;
        if (result < min_answer) min_answer = result;
        return;
    }

    for(int i=0; i < 4; i++) {
        if(oper_list[i] > 0) {
            oper_list[i]--;
            if(i == 0) 
                solution(result + num_list[index], index+1);
            else if(i == 1) 
                solution(result - num_list[index], index+1);
            else if(i == 2) 
                solution(result * num_list[index], index+1);
            else 
                solution(result / num_list[index], index+1);
            oper_list[i]++;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) 
        cin >> num_list[i];
    for(int i=0; i < 4; i++)
        cin >> oper_list[i];

    solution(num_list[0], 1);
    cout << max_answer << '\n';
    cout << min_answer;

    return 0;
}