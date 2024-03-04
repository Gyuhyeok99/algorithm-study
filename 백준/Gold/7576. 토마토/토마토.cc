#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int y, x, ret, n, m, a[1004][1004];
queue<pair<int, int>> q;
void bfs() {
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            if(a[ny][nx] == 0) {
                a[ny][nx] = a[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    return;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
            ret = max(ret, a[i][j]);
        }
    }
    cout << ret - 1 << "\n";
    return 0;
}
