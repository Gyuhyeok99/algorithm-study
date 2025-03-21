#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = -1;

vector<vector<int>> d;
void solve(int idx, int cnt, int cur, int n) {
    if(idx == n) {
        answer = max(answer, cnt);
        return;
    }
    solve(idx + 1, cnt, cur, n);
    if(d[idx][0] <= cur) {
        solve(idx + 1, cnt + 1, cur - d[idx][1], n);
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    
    sort(dungeons.begin(), dungeons.end());
    do {
        d = dungeons;
        solve(0, 0, k, dungeons.size());
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    return answer;
}