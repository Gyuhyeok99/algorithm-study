#include <iostream>
#include <map>
using namespace std;


const int INF = 987654321;
int n = 10, ret = INF;
int arr[11][11];
map<int, int> mp;

bool check(int y, int x, int cnt) {
    for(int i = y; i < y + cnt; i++) {
        for(int j = x; j < x + cnt; j++) {
            if(arr[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void draw(int y, int x, int cnt, int d) {
    for(int i = y; i < y + cnt; i++) {
        for(int j = x; j < x + cnt; j++) {
            arr[i][j] = d;
        }
    }
}
void dfs(int y, int x, int cnt) {
    if(cnt >= ret) {
        return;
    }
    if(x == n) {
        dfs(y + 1, 0, cnt);
        return;
    }
    if(y == n) {
        ret = min(cnt, ret);
    }
    if(arr[y][x] == 0) {
        dfs(y, x + 1, cnt);
        return;
    }
    for(int i = 5; i >= 1; i--) {
        if(check(y, x, i)) {
            if(mp[i] >= 5) {
                continue;
            }
            mp[i]++;
            draw(y, x, i, 0);
            dfs(y, x + 1, cnt + 1);
            draw(y, x, i, 1);
            mp[i]--;
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0, 0, 0);
    if(ret == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << ret << '\n';
    }
    return 0;
}