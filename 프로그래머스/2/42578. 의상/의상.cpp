#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> mp;
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    for(auto v : clothes) {
        mp[v[1]]++;
    }
    int ret = 1;
    for(auto it : mp) {
        ret *= (it.second + 1);
    }
    ret--;
    answer = ret;
    return answer;
}