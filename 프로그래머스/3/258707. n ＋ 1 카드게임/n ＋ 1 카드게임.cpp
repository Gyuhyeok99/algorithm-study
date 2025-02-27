#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    vector<int> my;   // 내 카드
    vector<int> wait; // 대기 카드

    int n = cards.size();

    // 처음 카드 분배
    for (int i = 0; i < n / 3; i++) {
        my.push_back(cards[i]);
    }

    // 남은 카드 대기열에 추가
    for (int i = n / 3; i < n; i += 2) {
        if (i < n) wait.push_back(cards[i]);
        if (i + 1 < n) wait.push_back(cards[i + 1]);

        // (1) 내 카드끼리 합이 n인지 체크
        for (int j = 0; j < my.size(); j++) {
            for (int k = j + 1; k < my.size(); k++) { // ✅ 중복 체크 방지 (j != k)
                if (my[j] + my[k] == n) {
                    answer++;
                    goto NEXT_ROUND; // ✅ 매칭되면 바로 다음 라운드 진행
                }
            }
        }

        // (2) 코인이 1개 이상 있으면 내 카드 + 대기 카드 체크
        if (coin >= 1) {
            for (int j = 0; j < my.size(); j++) {
                for (int k = 0; k < wait.size(); k++) {
                    if (my[j] + wait[k] == n) {
                        answer++;
                        coin--;
                        wait.erase(wait.begin() + k); // ✅ 요소 삭제 후 다음 루프
                        goto NEXT_ROUND;
                    }
                }
            }
        }

        // (3) 코인이 2개 이상 있으면 대기 카드 두 장 사용 가능
        if (coin >= 2 && wait.size() >= 2) {
            for (int j = 0; j < wait.size(); j++) {
                for (int k = j + 1; k < wait.size(); k++) { // ✅ 중복 제거
                    if (wait[j] + wait[k] == n) {
                        answer++;
                        coin -= 2;
                        wait.erase(wait.begin() + k);
                        wait.erase(wait.begin() + j); // ✅ 뒤에서 삭제
                        goto NEXT_ROUND;
                    }
                }
            }
        }

    NEXT_ROUND:; // ✅ 한 번이라도 매칭되면 다음 라운드로
    }

    return answer;
}
