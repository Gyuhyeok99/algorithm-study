#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n, r, l, ret, sum;
int arr[51][51], visited[51][51];
bool flag = true;
vector<pair<int, int>> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    v.push_back({y, x});
    sum += arr[y][x];
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) {
            continue;
        }
        int temp = abs(arr[ny][nx] - arr[y][x]);
        if(temp >= r && temp <= l) {
            dfs(ny, nx);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> r >> l;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    while(1) {
        flag = true;
        memset(visited, 0, sizeof(visited));
        v.clear();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    sum = 0;
                    dfs(i, j);
                    if(v.size() >= 2) {
                        int temp = sum / v.size();
                        for(auto a : v) {
                            arr[a.first][a.second] = temp;
                        }
                        flag = false;
                    }
                    v.clear();
                }
            }
        }
        if(flag) {
            break;
        }
        ret++;
    }
    cout << ret << '\n';
    return 0;
}