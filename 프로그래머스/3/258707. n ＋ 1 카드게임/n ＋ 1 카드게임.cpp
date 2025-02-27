#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool match(vector<int>& v1, vector<int>& v2, int target, bool isSame) {
    for(int i = 0; i < v1.size(); i++) {
        for(int j = 0; j < v2.size(); j++) {
            if(isSame && i == j) {
                continue;
            }
            if(v1[i] + v2[j] == target) {
                v1.erase(v1.begin() + i);
                v2.erase(v2.begin() + j - (isSame ? 1 : 0));
                return true;
            }
        }
    }
    return false;
}


int solution(int coin, vector<int> cards) {
    int answer = 1;
    vector<int> my;
    vector<int> wait;
    for(int i = 0; i < cards.size() / 3; i++) {
        my.push_back(cards[i]);
    }
    for(int i = cards.size() / 3; i < cards.size(); i += 2) {
        wait.push_back(cards[i]);
        wait.push_back(cards[i + 1]);
        
        if(match(my, my, cards.size() + 1, true)) {
        }
        else if(coin >= 1 && match(my, wait, cards.size() + 1, false)) {
            coin--;
        }
        else if(coin >= 2 && match(wait, wait, cards.size() + 1, true)) {
            coin -= 2;
        }
        else {
            break;
        }
        answer++;
    }     
    return answer;
}