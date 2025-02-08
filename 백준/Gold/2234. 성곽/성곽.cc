#include <iostream>
using namespace std;

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int n, m, cnt, answer_1, answer_2, answer_3;
int arr[51][51], visited[51][51], comp[51];

int dfs(int y, int x, int c) {
    visited[y][x] = c;
    int ret = 1;
    for(int i = 0; i < 4; i++) {
        if(!(arr[y][x] & (1 << i))) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!visited[ny][nx]) {
                ret += dfs(ny, nx, c);
            }
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j]){
                cnt++;
                comp[cnt] = dfs(i, j, cnt);
                answer_2 = max(answer_2, comp[cnt]);
            }

        }
    }
    answer_1 = cnt;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i + 1 < n) {
                int a = visited[i + 1][j];
                int b = visited[i][j];
                if(a != b) {
                    answer_3 = max(answer_3, comp[a] + comp[b]);
                }
            }
            if(j + 1 < m) {
                int a = visited[i][j + 1];
                int b = visited[i][j];
                if(a != b) {
                    answer_3 = max(answer_3, comp[a] + comp[b]);
                }
            }
        }
    }
    cout << answer_1 << '\n' << answer_2 << '\n' << answer_3 << '\n';
    return 0;
}