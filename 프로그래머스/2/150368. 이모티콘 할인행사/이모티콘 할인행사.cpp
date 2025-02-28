#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int discount[] = {10, 20, 30, 40};
vector<int> answer(2);
vector<vector<int>> c_users;
vector<int> c_emoticons;
vector<pair<int, int>> price(7);

void dfs(int idx, int n) {
    if(idx == n) {
        int plus = 0, sum = 0;
        for(int i = 0; i < c_users.size(); i++) {
            int temp = 0;
            for(int j = 0; j < c_emoticons.size(); j++) {
                if(c_users[i][0] <= price[j].first) {
                    temp += price[j].second;
                }
            }
            if(c_users[i][1] <= temp) {
                plus++;
            }
            else {
                sum += temp; 
            }
        }
        if(answer[0] < plus) {
            answer[0] = plus;
            answer[1] = sum;
        }
        else if(answer[0] == plus) {
            answer[1] = max(answer[1], sum);
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        price[idx].first = discount[i];
        price[idx].second = (100 - discount[i]) * c_emoticons[idx] / 100;
        dfs(idx + 1, n);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    c_users = users;
    c_emoticons = emoticons;
    dfs(0, c_emoticons.size());
    return answer;
}