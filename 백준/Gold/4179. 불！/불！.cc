#include <iostream>
#include <queue>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char arr[1001][1001];
int jihun[1001][1001], fire[1001][1001];
int r, c, ret;
pair<int, int> s_ji;
queue<pair<int, int>> q;
bool flag = false;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < c; j++) {
            arr[i][j] = s[j];
            if(s[j] == 'J') {
                s_ji = {i, j};
            }
            else if(s[j] == 'F') {
                q.push({i, j});
                fire[i][j] = 1;
            }
        }
    }

    while(q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
                continue;
            }
            if(arr[ny][nx] == '#' || fire[ny][nx] != 0) {
                continue;
            }
            fire[ny][nx] = fire[y][x] + 1;
            q.push({ny, nx});
        }
    }

    q.push({s_ji.first, s_ji.second});
    jihun[s_ji.first][s_ji.second] = 1;
    while(q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == 0 || x == 0 || y == r - 1 || x == c - 1) {
            ret = jihun[y][x];
            flag = true;
            break;
        }
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
                continue;
            }
            if(arr[ny][nx] == '#' || jihun[ny][nx] != 0) {
                continue;
            }
            if(fire[ny][nx] && jihun[y][x] + 1 >= fire[ny][nx]) {
                continue;
            }
            jihun[ny][nx] = jihun[y][x] + 1;
            q.push({ny, nx});
        }
    }

    if(flag) {
        cout << ret << '\n';
    }else {
        cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
}