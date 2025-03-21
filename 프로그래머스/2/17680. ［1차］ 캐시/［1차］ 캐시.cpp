#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> cache;
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for(string& s : cities) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - ('A' - 'a');
            }
        }
    }
    for(int i = 0; i < cities.size(); i++) {
        bool hit = false;
        for(int j = 0; j < cache.size(); j++) {
            if(cache[j] == cities[i]) {
                cache.erase(cache.begin() + j);
                cache.push_back(cities[i]);
                hit = true;
                break;
            }
        }
        if(hit) {
            answer++;
        }
        else{
            if(cacheSize > 0) {
                if(cache.size() == cacheSize) {
                cache.erase(cache.begin());
            }
                cache.push_back(cities[i]);
            }
            answer += 5;
        }
    }
    return answer;
}