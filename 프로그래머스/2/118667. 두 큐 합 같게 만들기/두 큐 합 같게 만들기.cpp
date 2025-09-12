#include <string>
#include <vector>
#include <queue>

using namespace std;

long long _sum, ret, sum1;
queue<int> q1, q2;
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    for(int q : queue1) {
        q1.push(q);
        _sum += q;
        sum1 += q;
    }
    
    for(int q : queue2) {
        q2.push(q);
        _sum += q;
    }
    if (_sum % 2 != 0) {
        return -1;
    }
    
    ret = _sum / 2;
    
    while(sum1 != ret) {
        answer++;
        if(answer > (q1.size() + q2.size()) * 2) {
            return -1;
        }
        if(sum1 > ret) {
            int value = q1.front();
            sum1 -= value;
            q2.push(value);
            q1.pop();
        }
        else {
            int value = q2.front();
            sum1 += value;
            q1.push(value);
            q2.pop();
        }
    }
    return answer;
}