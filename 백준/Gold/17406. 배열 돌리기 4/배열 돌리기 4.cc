#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m, r, c, s, k, sy, sx, ey, ex, dir, ret = INF;
int arr[51][51], brr[51][51], visited[51][51];
vector<pair<int, int>> vv;
vector<int> v_idx;
struct A{
    int y, x, c;
};
vector<A> v;

void go(int y, int x, int first) {
    if(!first && y == sy && x == ex) dir++;
    if(!first && y == ey && x == ex) dir++;
    if(!first && y == ey && x == sx) dir++;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(visited[ny][nx]) {
        return;
    }
    visited[ny][nx] = 1;
    vv.push_back({ny, nx});
    go(ny, nx, 0);
}

void rotateAll(int y, int x, int cnt) {
    for(int i = 1; i <= cnt; i++) {
        sy = y - 1 * i;
        sx = x - 1 * i;
        ey = y + 1 * i;
        ex = x + 1 * i;
        vv.clear();
        dir = 0;
        memset(visited, 0 , sizeof(visited));
        visited[sy][sx] = 1;
        vv.push_back({sy, sx});
        go(sy, sx, 1);

        vector<int> vvv;
        for(pair<int, int> c: vv) {
            vvv.push_back(brr[c.first][c.second]);
        }
        rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend());
        for(int i = 0; i < vv.size(); i ++) {
            brr[vv[i].first][vv[i].second] = vvv[i];
        }
    }
}

int solve() {
    for(int i : v_idx) {
        rotateAll(v[i].y, v[i].x, v[i].c);
    }
    int mn = INF;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            cnt += brr[i][j];
        }
        mn = min(mn, cnt);
    }
    return mn;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>> arr[i][j];
        }
    }
    for(int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        r--; c--;
        v.push_back({r, c, s});
        v_idx.push_back(i);
    }
    do {
        memcpy(brr, arr, sizeof(arr));
        ret = min(ret, solve());
    } while(next_permutation(v_idx.begin(), v_idx.end()));
    cout << ret << '\n';
    return 0;
}