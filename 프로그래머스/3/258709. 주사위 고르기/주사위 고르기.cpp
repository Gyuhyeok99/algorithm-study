#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, m;
vector<int> answer;
vector<vector<int>> d;

void solve(int idx, int sum, vector<int>& chosen, vector<int>& s) {
    if(idx == chosen.size()) {
        s.push_back(sum);
        return;
    }
    for(int i = 0; i < 6; i++) {
        solve(idx + 1, sum + d[chosen[idx]][i], chosen, s);
    }
}

void combi(int start, vector<int> a) {
    if(a.size() == k) {
        vector<int> b;
        for(int i = 0; i < d.size(); i++) {
            if(find(a.begin(), a.end(), i) == a.end()) {
                b.push_back(i);
            }
        }
        vector<int> sumA, sumB;
        solve(0, 0, a, sumA);
        solve(0, 0, b, sumB);
        
        sort(sumB.begin(), sumB.end());
        
        int win = 0;
        for(int i : sumA) {
            win += lower_bound(sumB.begin(), sumB.end(), i) - sumB.begin();
        }
        
        if(win > m) {
            m = win;
            answer = a;
        }
        return;
    }
    for(int i = start + 1; i < n; i++) {
        a.push_back(i);
        combi(i, a);
        a.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) {
    d = dice;
    n = dice.size();
    k = n / 2;
    
    combi(-1, {});
    
    for(int & i : answer) {
        i++;
    }
    return answer;
}