#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int attack[6][3] = {
        9, 3, 1,
        9, 1, 3,
        3, 9, 1,
        3, 1, 9,
        1, 3, 9,
        1, 9, 3
};
int s[3], visited[61][61][61];
int n;
struct scv{
    int a, b, c;
};
queue<scv> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    q.push({s[0], s[1], s[2]});
    visited[s[0]][s[1]][s[2]] = 1;
    while(q.size()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if(visited[0][0][0]) {
            break;
        }
        for(int i = 0; i < 6; i++) {
            int n_a = max(0, a - attack[i][0]);
            int n_b = max(0, b - attack[i][1]);
            int n_c = max(0, c - attack[i][2]);
            if(visited[n_a][n_b][n_c]) {
                continue;
            }
            visited[n_a][n_b][n_c] = visited[a][b][c] + 1;
            q.push({n_a, n_b, n_c});
        }
    }
    cout << visited[0][0][0] - 1 << '\n';
    return 0;
}