#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

map<string, int> m;  // 사용자 ID → 인덱스 매핑
vector<int> count(1001, 0);  // 신고 당한 횟수
vector<set<int>> r(1001);  // 🚨 신고한 사람을 **신고당한 유저 기준으로 저장**

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);  // 각 유저가 받은 결과 메일 개수

    // 1️⃣ ID를 인덱스로 매핑
    for (int i = 0; i < id_list.size(); i++) {
        m[id_list[i]] = i;
    }

    // 2️⃣ 신고 기록 처리 (중복 방지)
    for (string rep : report) {
        stringstream ss(rep);
        string from, to;
        ss >> from >> to;
        int from_idx = m[from];
        int to_idx = m[to];

        if (r[to_idx].find(from_idx) == r[to_idx].end()) {  // 🚨 신고한 사람을 신고당한 유저 기준으로 저장
            r[to_idx].insert(from_idx);
            count[to_idx]++;  // 신고 당한 횟수 증가
        }
    }

    // 3️⃣ 정지된 사용자 확인 후, 신고한 유저에게 메일 카운트 증가
    for (int i = 0; i < id_list.size(); i++) {
        if (count[i] >= k) {  // 🚨 k번 이상 신고된 사용자
            for (int reporter : r[i]) {  // 🚨 신고한 유저에게 메일 전송
                answer[reporter]++;  
            }
        }
    }

    return answer;
}
