#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int discount[] = {10, 20, 30, 40};
vector<int> answer(2);
vector<pair<int, int>> price(7);
vector<vector<int>> u;
vector<int> e;

void dfs(int idx, int n) {
    if(idx == n) {
        int plus = 0;
        int sum = 0;
        for(int i = 0; i < u.size(); i++) {
            int tmp = 0;
            for(int j = 0; j < n; j++) {
                if(u[i][0] <= price[j].second) {
                    tmp += price[j].first;
                }
            }
            if(u[i][1] <= tmp) {
                plus++;
            }
            else {
                sum += tmp;
            } 
        }
        if(answer[0] < plus) {
            answer[0] = plus;
            answer[1] = sum;
        }
        else if(answer[0] == plus) {
            answer[1] = max(sum, answer[1]);
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        price[idx].first = (100 - discount[i]) * e[idx] / 100;
        price[idx].second = discount[i];
        dfs(idx + 1, n);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    u = users;
    e = emoticons;
    dfs(0, e.size());
    return answer;
}