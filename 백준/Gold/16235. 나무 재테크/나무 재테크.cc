#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k, ret;
int arr[11][11], yang[11][11];
vector<int> v[11][11];

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void springSummer() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp = 0;
            vector<int> temp_v;
            sort(v[i][j].begin(), v[i][j].end());
            for(int jj = 0; jj < v[i][j].size(); jj++) {
                if(yang[i][j] > 0 && v[i][j][jj] <= yang[i][j]) {
                    yang[i][j] -= v[i][j][jj];
                    temp_v.push_back(v[i][j][jj] + 1);
                }
                else {
                    temp += v[i][j][jj] / 2;
                }
            }
            yang[i][j] += temp;
            v[i][j] = temp_v;
        }
    }
}

void fall() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int jj = 0; jj < v[i][j].size(); jj++) {
                if(v[i][j][jj] % 5 == 0) {
                    for(int jjj = 0 ; jjj < 8; jjj++) {
                        int ny = i + dy[jjj];
                        int nx = j + dx[jjj];
                        if(ny < 0 || nx < 0 || ny >= n || nx >= n) {
                            continue;
                        }
                        v[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
}

void winter() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            yang[i][j] += arr[i][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    fill(&yang[0][0], &yang[0][0] + 11 * 11, 5);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        v[x][y].push_back(z);
    }
    for(int i = 0; i < k; i++) {
        springSummer();
        fall();
        winter();
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ret += v[i][j].size();
        }
    }
    cout << ret << '\n';
    return 0;
}