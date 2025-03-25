#include <string>
#include <vector>

using namespace std;

int answer = 0;
string s = "";
string mo = "AEIOU";

int cnt = -1;
void dfs(string here, string word) {
    if(here.size() > 5) {
        return;
    }
    cnt++;
    if(here == word) {
        answer = cnt;
        return;
    }
    for(int i = 0; i < 5; i++) {
        dfs(here + mo[i], word);
    }
    return;
}
int solution(string word) {
    
    dfs(s, word);
    return answer;
}