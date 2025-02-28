#include <string>
#include <vector>
#include <queue>

using namespace std;

long long sumA, sumB, avg;
int cnt;
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    deque<int> dq1(queue1.begin(), queue1.end());
    deque<int> dq2(queue2.begin(), queue2.end());

    for(int i : queue1) {
        sumA += i;
        
    }
    for(int i : queue2) {
        sumB += i;
    }
    avg = (sumA + sumB) / 2;
    
    int limit = (queue1.size() + queue2.size()) * 4;
    while((sumA != sumB)) {
        if(cnt > limit) {
            break;
        }
        if(dq1.empty() || dq2.empty()) {
            break;
        }
        if(sumA > sumB) {
            int x = dq1.front();
            dq1.pop_front();
            dq2.push_back(x);
            sumA -= x;
            sumB += x;
        }
        else {
            int x = dq2.front();
            dq2.pop_front();
            dq1.push_back(x);
            sumA += x;
            sumB -= x;
        }
        cnt++;
    }
    if(sumA == sumB) {
        answer = cnt;
    }
    return answer;
}