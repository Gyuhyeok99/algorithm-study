#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, t;
int arr[51][51], tmp[51][51];
int wind;
long long ret;
void dfs(int y, int x) {
    int cnt = 0;
    int temp = arr[y][x] / 5;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == -1) {
            continue;
        }
        cnt++;
        tmp[ny][nx] += temp;
    }
    arr[y][x] -= temp * cnt;
}
void wide() {
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == -1 || arr[i][j] == 0) {
                continue;
            }
            dfs(i, j);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] += tmp[i][j];
        }
    }
    return;
}

void up_cleaner() {
    vector<int> v;
    for(int i = 1; i < m - 1; i++) {
        v.push_back(arr[wind - 1][i]);
    }
    for(int i = wind - 1; i > 0; i--) {
        v.push_back(arr[i][m - 1]);
    }
    for(int i = m - 1; i >= 1; i--) {
        v.push_back(arr[0][i]);
    }
    for(int i = 0; i < wind - 1; i++) {
        v.push_back(arr[i][0]);
    }
    rotate(v.rbegin(), v.rbegin() + 1, v.rend());
    v[0] = 0;
    int idx = 0;
    for(int i = 1; i < m - 1; i++) {
        arr[wind - 1][i] = v[idx++];
    }
    for(int i = wind - 1; i > 0; i--) {
        arr[i][m - 1] = v[idx++];
    }
    for(int i = m - 1; i >= 1; i--) {
        arr[0][i] = v[idx++];
    }
    for(int i = 0; i < wind - 1; i++) {
        arr[i][0] = v[idx++];
    }
    return;
}

void down_cleaner() {
    vector<int> v;
    for(int i = 1; i < m - 1; i++) {
        v.push_back(arr[wind][i]);
    }
    for(int i = wind; i < n - 1; i++) {
        v.push_back(arr[i][m - 1]);
    }
    for(int i = m - 1; i >= 1; i--){
        v.push_back(arr[n - 1][i]);
    }
    for(int i = n - 1; i > wind; i--) {
        v.push_back(arr[i][0]);
    }
    rotate(v.rbegin(), v.rbegin() + 1, v.rend());
    v[0] = 0;
    int idx = 0;
    for(int i = 1; i < m - 1; i++) {
        arr[wind][i] = v[idx++];
    }
    for(int i = wind; i < n - 1; i++) {
        arr[i][m - 1] = v[idx++];
    }
    for(int i = m - 1; i >= 1; i--){
        arr[n - 1][i] = v[idx++];
    }
    for(int i = n - 1; i > wind; i--) {
        arr[i][0] = v[idx++];
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == -1) {
                wind = i;
            }
        }
    }
    while(t--) {
        wide();
        up_cleaner();
        down_cleaner();
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == -1) {
                continue;
            }
            ret += arr[i][j];
        }
    }
    cout << ret << '\n';
    return 0;
}