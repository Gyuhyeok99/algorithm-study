#include <iostream>
#include <algorithm>
using namespace std;

int dy[] = {-1 ,0, 1, 0};
int dx[] = {0, 1, 0, -1};
int a[11][11], visited[11][11];
int n, ret = 987654321;

int setFlower(int y, int x) {
    visited[y][x] = 1;
    int sum = a[y][x];
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        sum += a[ny][nx];
        visited[ny][nx] = 1;
    }
    return sum;
}

void eraseFlower(int y, int x) {
    visited[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
    return;
}

bool check(int y, int x) {
    if(visited[y][x]) {
        return 0;
    }
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) {
            return 0;
        }
    }
    return 1;
}

void go(int cnt, int sum) {
    if(cnt == 3) {
        ret = min(ret, sum);
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(check(i, j)) {
                go(cnt + 1, sum + setFlower(i, j));
                eraseFlower(i, j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    go(0, 0);
    cout << ret << '\n';
    return 0;
}