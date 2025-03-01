#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> d;
int n, k;
int max_cnt;
vector<int> answer;
void getSum(int idx, int sum, vector<int>& selectedX, vector<int>& sumX) {
    if(idx == selectedX.size()) {
        sumX.push_back(sum);
        return;
    }
    for(int i = 0; i < 6; i++) {
        getSum(idx + 1, sum + d[selectedX[idx]][i] , selectedX, sumX);
    }
    return;
}

void combi(int start, vector<int> selectedA) {
    if(selectedA.size() == k) {
        vector<int> selectedB;
        for(int i = 0; i < n; i++) {
            if(find(selectedA.begin(), selectedA.end(), i) == selectedA.end()) {
                selectedB.push_back(i);
            }
        }
        vector<int> sumA;
        vector<int> sumB;
        getSum(0, 0, selectedA, sumA);
        getSum(0, 0, selectedB, sumB);
        
        sort(sumB.begin(), sumB.end());
        int cnt = 0;
        for(int a : sumA) {
            cnt += lower_bound(sumB.begin(), sumB.end(), a) - sumB.begin();
        }
        
        if(cnt > max_cnt) {
            max_cnt = cnt;
            answer = selectedA;
        }
        return;
    }
    for(int i = start + 1; i < n; i++) {
        selectedA.push_back(i);
        combi(i, selectedA);
        selectedA.pop_back();
    }
    return;
}

vector<int> solution(vector<vector<int>> dice) {
    d = dice;
    n = d.size();
    k = n / 2;
    combi(-1, {});
    
    for(int & i : answer) {
        i++;
    }
    return answer;
}