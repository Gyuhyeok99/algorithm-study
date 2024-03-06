#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
const int _MAX = 102;
const int dz[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 0, 0, 1, -1};
const int dx[] = {0, 0, -1, 1, 0, 0};
int n, m, h, z, y, x, ret, a[_MAX][_MAX][_MAX];
queue<tuple<int, int, int>> q;

void bfs() {
    while(q.size()) {
        tie(z, y, x) = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m) {
                continue;
            }
            if (a[nz][ny][nx] == 0) {
                a[nz][ny][nx] = a[z][y][x] + 1;
                q.push({nz, ny, nx});
            }
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> a[i][j][k];
                if(a[i][j][k] == 1) {
                    q.push({i, j, k});
                }
            }
        }
    }
    bfs();
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(a[i][j][k] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                ret = max(ret, a[i][j][k]);
            }
        }
    }
    cout << ret - 1 << '\n';
    return 0;
}
