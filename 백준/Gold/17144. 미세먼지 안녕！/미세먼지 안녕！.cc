#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dy1[] = {0, -1, 0, 1};
const int dx1[] = {1, 0, -1, 0};
const int dy2[] = {0, 1, 0, -1};
const int dx2[] = {1, 0, -1, 0};
int arr[51][51], temp[51][51], n, m, t, ret;
vector<pair<int, int>> v1, v2;
bool flag = true;

void miseCleaner(int y, int x) {
    int mount = arr[y][x] / 5;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy1[i];
        int nx = x + dx1[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == -1) {
            continue;
        }
        temp[ny][nx] += mount;
        arr[y][x] -= mount;
    }
    return;
}

void rota(vector<pair<int, int>> & v) {
    for(int i = v.size() - 1; i > 0; i--) {
        arr[v[i].first][v[i].second] = arr[v[i - 1].first][v[i -1].second];
    }
    arr[v[0].first][v[0].second] = 0;
    return;
}

vector<pair<int, int>> pathCleaner(int sy, int sx, const int dy[], const int dx[]) {
    vector<pair<int, int>> v;
    int cnt = 0;
    int y = sy;
    int x = sx;
    while(1) {
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];
        if(ny == sy && nx == sx) {
            break;
        }
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
            cnt++;
            continue;
        }
        y = ny; x = nx;
        v.push_back({ny, nx});
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];

            if(arr[i][j] == -1) {
                if(flag) {
                    v1 = pathCleaner(i, j, dy1, dx1);
                    flag = false;
                }
                else {
                    v2 = pathCleaner(i, j, dy2, dx2);
                }
            }
        }
    }

    while(t--) {
        memset(temp, 0, sizeof(temp));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] != -1 && arr[i][j]) {
                    miseCleaner(i, j);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[i][j] += temp[i][j];
            }
        }
        rota(v1);
        rota(v2);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] != -1) {
                ret += arr[i][j];
            }
        }
    }
    cout << ret << '\n';
    return 0;
}