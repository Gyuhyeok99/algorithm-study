#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt = __builtin_popcount(n);
    while(1) {
        int nn = ++n;
        int next_cnt = __builtin_popcount(n);
        if(cnt == next_cnt) {
            answer = nn;
            break;
        }
    }
    cout << __builtin_popcount(n) << '\n';
    return answer;
}