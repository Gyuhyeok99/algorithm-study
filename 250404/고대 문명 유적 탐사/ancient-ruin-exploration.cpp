#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n = 5, k, m, ret_sum, ret_y, ret_x, ret_dir, ret;
int arr[5][5], visited[5][5], temp[5][5];
queue<int> q;
vector<pair<int, int>> vvv;
int dfs(int y, int x, int num) {
    visited[y][x] = 1;
    int cnt = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) {
            continue;
        }
        if(temp[ny][nx] != num) {
            continue;
        }
        cnt += dfs(ny, nx, num);
    }
    return cnt;
}

void dfs2(int y, int x, int num) {
    visited[y][x] = 1;
    vvv.push_back({y, x});
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) {
            continue;
        }
        if(arr[ny][nx] != num) {
            continue;
        }
        dfs2(ny, nx, num);
    }
    return;
}

void rotateU(int y, int x, int dir) {
    vector<int> v;
    for(int i = x; i < x + 2; i++) {
        v.push_back(temp[y][i]);
    }
    for(int i = y; i < y + 2; i++) {
        v.push_back(temp[i][x + 2]);
    }
    for(int i = x + 2; i > x; i--) {
        v.push_back(temp[y + 2][i]);
    }
    for(int i = y + 2; i > y; i--) {
        v.push_back(temp[i][x]);
    }
        rotate(v.rbegin(), v.rbegin() + 2 * dir, v.rend());
        int idx = 0;
        for(int i = x; i < x + 2; i++) {
            temp[y][i] = v[idx++];
        }
        for(int i = y; i < y + 2; i++) {
            temp[i][x + 2] = v[idx++];
        }
        for(int i = x + 2; i > x; i--) {
            temp[y + 2][i] = v[idx++];
        }
        for(int i = y + 2; i > y; i--) {
            temp[i][x] = v[idx++];
        }
        memset(visited, 0, sizeof(visited));
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    int cnt = dfs(i, j, temp[i][j]);
                    if(cnt >= 3) {
                        sum += cnt;
                    }
                }
            }
        }
        if(ret_sum < sum) {
            ret_sum = sum;
            ret_y = y;
            ret_x = x;
            ret_dir = dir;
        }
    return;
}

int rotateU2(int y, int x, int dir) {
    vector<int> v;
    for(int i = x; i < x + 2; i++) {
        v.push_back(arr[y][i]);
    }
    for(int i = y; i < y + 2; i++) {
        v.push_back(arr[i][x + 2]);
    }
    for(int i = x + 2; i > x; i--) {
        v.push_back(arr[y + 2][i]);
    }
    for(int i = y + 2; i > y; i--) {
        v.push_back(arr[i][x]);
    }
    
        rotate(v.rbegin(), v.rbegin() + 2 * dir, v.rend());
        int idx = 0;
        for(int i = x; i < x + 2; i++) {
            arr[y][i] = v[idx++];
        }
        for(int i = y; i < y + 2; i++) {
            arr[i][x + 2] = v[idx++];
        }
        for(int i = x + 2; i > x; i--) {
            arr[y + 2][i] = v[idx++];
        }
        for(int i = y + 2; i > y; i--) {
            arr[i][x] = v[idx++];
        }
        memset(visited, 0, sizeof(visited));
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    vvv.clear();
                    dfs2(i, j, arr[i][j]);
                    if(vvv.size() >= 3) {
                        for(auto aa : vvv) {
                            arr[aa.first][aa.second] = 0;
                        }
                        sum += vvv.size();
                    }
                }
            }
        }
    return sum;
}
void searchU(int y, int x, int dir) {
    if(y == 3 && x == 2) {
        return;
    }
    if(y == 3) {
        y = 0;
        x++;
    }
    memcpy(temp, arr, sizeof(arr));
    rotateU(y, x, dir);
    
    searchU(y + 1, x, dir);
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        q.push(num);
    }

    while(k--){
    ret = 0;
    ret_sum = 0;
    ret_y = -1, ret_x = -1, ret_dir = -1;
    for(int i = 1; i <= 3; i++) {
        searchU(0, 0, i);
    }
    if(ret_sum == 0) {
        return 0;
    }
    ret += rotateU2(ret_y, ret_x, ret_dir);
    while(1){
        for(int j = 0; j < n; j++) {
            for(int i = n - 1; i >= 0; i--) {
                if(arr[i][j] == 0) {
                    arr[i][j] = q.front();
                    q.pop();
                }
            }
        }
        int sum = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    vvv.clear();
                    dfs2(i, j, arr[i][j]);
                    if(vvv.size() >= 3) {
                        for(auto aa : vvv) {
                            arr[aa.first][aa.second] = 0;
                        }
                        sum += vvv.size();
                    }
                }
            }
        }
        if(sum == 0) {
            break;
        }
        else {
            ret += sum;
        }
    }
    cout << ret << ' ';
    }
    return 0;
}