#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, ret, visited[26][26];
char a[26][26];
vector<int> cnt;
int dfs(int y, int x) {
    visited[y][x] = 1;
    int num = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == '0' || visited[ny][nx]) {
            continue;
        }
        num += dfs(ny, nx);
    }
    return num;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            a[i][j] = s[j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] == 0 && a[i][j] == '1') {
                cnt.push_back(dfs(i, j));
                ret++;
            }
        }
    }
    sort(cnt.begin(), cnt.end());
    cout << ret << '\n';
    for(int i : cnt) {
        cout << i << '\n';
    }
    return 0;
}
