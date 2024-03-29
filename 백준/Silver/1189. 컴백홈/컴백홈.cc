#include <iostream>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, visited[8][8];
char a[8][8];
int dfs(int y, int x) {
    if(y == 0 && x == m - 1) {
        if(k == visited[y][x]) {
            return 1;
    }
        return 0;
    }
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 'T') {
            continue;
        }
        visited[ny][nx] = visited[y][x] + 1;
        ret += dfs(ny, nx);
        visited[ny][nx] = 0;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    visited[n - 1][0] = 1;
    cout << dfs(n - 1, 0) << '\n';
    return 0;
}
