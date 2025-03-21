#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> mp;
bool solution(vector<string> phone_book) {
    bool answer = true;
    for(string s : phone_book) {
        mp[s]++;
    }
    for(string s : phone_book) {
        if(answer == false) {
            break;
        }
        for(int i = 1; i < s.size(); i++) {
            string tmp = s.substr(0, i);
            if(mp[tmp]) {
                answer = false;
                break;
            }
        }
    }
    return answer;
}