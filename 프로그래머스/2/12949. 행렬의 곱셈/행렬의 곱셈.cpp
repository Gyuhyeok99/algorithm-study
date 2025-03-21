#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i = 0; i < arr1.size(); i++) {
    vector<int> row;
    for(int j = 0; j < arr2[0].size(); j++) {
        int sum = 0;
        for(int k = 0; k < arr2.size(); k++) { // ← 공통 차원 만큼 곱셈
            sum += arr1[i][k] * arr2[k][j];   // ← 올바른 인덱스 접근
        }
        row.push_back(sum); // ← 계산된 값 저장
    }
    answer.push_back(row); // ← 한 행씩 저장
}
    return answer;
}