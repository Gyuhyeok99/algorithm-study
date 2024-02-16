#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;
int n, m, ret, cnt, a[101][101], visited[101][101];

void dfs(int y, int x) {
    visited[y][x] = 1;
    if(a[y][x] == 1) {
        v.push_back({y, x});
        return;
    }
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] == 1) {
            continue;
        }
        dfs(ny, nx);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while(true) {
        memset(visited, 0, sizeof(visited));
        v.clear();
        dfs(0, 0);
        bool flag = 1;
        cnt = v.size();
        for(auto it : v) {
            a[it.first][it.second] = 0;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] != 0) {
                    flag = 0;
                }
            }
        }
        ret++;
        if(flag) {
            break;
        }
    }
    cout << ret << '\n' << cnt << '\n';
}