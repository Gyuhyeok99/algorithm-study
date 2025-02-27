#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> d;
int n, k;
vector<int> answer;
int maxCount;

void getSum(int idx, int sum, vector<int>& selected, vector<int>& s) {
    if(idx == selected.size()) {
        s.push_back(sum);
        return;
    }
    for(int i = 0; i < 6; i++) {
        getSum(idx + 1, sum + d[selected[idx]][i], selected, s);
    }
}

void combi(int start, vector<int> selectedA) {
    if(selectedA.size() == k) {
        //종료 시 해야할 조건
        vector<int> selectedB;
        for(int i = 0; i < n; i++) {
            if(find(selectedA.begin(), selectedA.end(), i) == selectedA.end()) {
                selectedB.push_back(i);
            }
        }
        vector<int> sumA, sumB;
        getSum(0, 0, selectedA, sumA);
        getSum(0, 0, selectedB, sumB);
        
        sort(sumB.begin(), sumB.end());
        
        int count = 0;
        for(int i : sumA) {
            count += lower_bound(sumB.begin(), sumB.end(), i) - sumB.begin();
        }
        if(count > maxCount) {
            maxCount = count;
            answer = selectedA;
        }
        return;
    }
    for(int i = start + 1; i < n; i++) {
        selectedA.push_back(i);
        combi(i, selectedA);
        selectedA.pop_back();
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