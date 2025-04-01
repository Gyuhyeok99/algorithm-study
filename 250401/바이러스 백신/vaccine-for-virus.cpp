#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, ret = -1, tmp;
int arr[51][51], visited[51][51], visited2[51][51];
vector<pair<int, int>> hos;
vector<vector<int>> selected;

void combi(int start, vector<int> b) {
    if(b.size() == m) {
        selected.push_back(b);
        return;
    }
    for(int i = start + 1; i < hos.size(); i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

bool check() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 0) {
                if(!visited2[i][j]) return false;
                tmp = max(tmp, visited[i][j]);
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) {
                hos.push_back({i, j});
            }
        }
    }
    combi(-1, {});
    for(auto s : selected) {
        memset(visited2, 0, sizeof(visited2));
        memset(visited, 0, sizeof(visited)); // 얘도 bfs 내부에서 방문 시간 기록용으로 같이 초기화
        queue<pair<int, int>> q;
        tmp = 0;

        for(int a : s) {
            int y = hos[a].first;
            int x = hos[a].second;
            q.push({y, x});
            visited2[y][x] = 1;
            visited[y][x] = 0; // 시작점은 시간 0
        }  

        // 한 번만 BFS 돌림
        while(q.size()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if(visited2[ny][nx] || arr[ny][nx] == 1) continue;
                    visited2[ny][nx] = 1;
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny, nx});
                }
            }
        if(check()) {
            if(ret == -1 || tmp < ret) {
                ret = tmp;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}