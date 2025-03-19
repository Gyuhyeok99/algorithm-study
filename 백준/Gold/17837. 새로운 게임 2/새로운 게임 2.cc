#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int n, k, ret;
int arr[13][13];
vector<int> v[13][13];
struct Point {
    int y, x, d;
};
vector<Point> p;
void move(int y, int x, int dir, int idx) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= n || nx >= n || arr[ny][nx] == 2) {
        p[idx].d ^= 1;
        ny = y + dy[p[idx].d];
        nx = x + dx[p[idx].d];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || arr[ny][nx] == 2) {
            return;
        }
    }
    vector<int>& here = v[y][x];
    vector<int>& next = v[ny][nx];
    auto pos = find(v[y][x].begin(), v[y][x].end(), idx);
    if(arr[ny][nx] == 1) {
        reverse(pos, v[y][x].end());
    }
    for(auto it = pos; it != v[y][x].end(); it++) {
        next.push_back(*it);
        p[*it].y = ny;
        p[*it].x = nx;
    }
    v[y][x].erase(pos, v[y][x].end());
    return;
}
bool gameEnd() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j].size() >= 4) {
                return true;
            }
        }
    }
    return false;
}
bool solve() {
    for(int i = 0; i < p.size(); i++) {
        int y = p[i].y;
        int x = p[i].x;
        int d = p[i].d;
        move(y, x, d, i);
        if(gameEnd()) {
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < k; i++) {
        int y, x, d;
        cin >> y >> x >> d;
        y--, x--, d--;
        p.push_back({y, x, d});
        v[y][x].push_back(i);
    }

    bool flag = false;
    while(ret <= 1000) {
        ret++;
        if(solve()) {
            flag = true;
            break;
        }
    }
    if(flag) {
        cout << ret << '\n';
    }
    else {
        cout << -1 << '\n';
    }
    return 0;
}
