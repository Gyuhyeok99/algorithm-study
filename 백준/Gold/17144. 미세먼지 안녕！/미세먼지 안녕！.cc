#include <iostream>
#include <vector>
#include <cstring> // memset 사용
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int arr1[51][51];
int arr2[51][51];
vector<pair<int, int>> cleaner;
int r, c, t;

void solve(int y, int x) {
    int spread_amount = arr1[y][x] / 5;
    int spread_count = 0;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;

        if((ny == cleaner[0].first && nx == cleaner[0].second) ||
           (ny == cleaner[1].first && nx == cleaner[1].second)) {
            continue;
        }

        arr2[ny][nx] += spread_amount;
        spread_count++;
    }
    arr2[y][x] -= spread_amount * spread_count;
}

void air_cleaner() {
    int up = cleaner[0].first;
    int down = cleaner[1].first;

    for(int i = up - 1; i > 0; i--) arr1[i][0] = arr1[i - 1][0]; // 아래로 이동
    for(int i = 0; i < c - 1; i++) arr1[0][i] = arr1[0][i + 1]; // 왼쪽에서 오른쪽 이동
    for(int i = 0; i < up; i++) arr1[i][c - 1] = arr1[i + 1][c - 1]; // 위로 이동
    for(int i = c - 1; i > 1; i--) arr1[up][i] = arr1[up][i - 1]; // 오른쪽에서 왼쪽 이동
    arr1[up][1] = 0; // 공기청정기에서 나오는 부분

    // 아래쪽 공기청정기 (시계 방향)
    for(int i = down + 1; i < r - 1; i++) arr1[i][0] = arr1[i + 1][0]; // 위로 이동
    for(int i = 0; i < c - 1; i++) arr1[r - 1][i] = arr1[r - 1][i + 1]; // 왼쪽에서 오른쪽 이동
    for(int i = r - 1; i > down; i--) arr1[i][c - 1] = arr1[i - 1][c - 1]; // 아래로 이동
    for(int i = c - 1; i > 1; i--) arr1[down][i] = arr1[down][i - 1]; // 오른쪽에서 왼쪽 이동
    arr1[down][1] = 0; // 공기청정기에서 나오는 부분
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> t;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr1[i][j];
            if(arr1[i][j] == -1) {
                cleaner.push_back({i, j});
            }
        }
    }

    while(t--) {
        memset(arr2, 0, sizeof(arr2));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(arr1[i][j] > 0) {
                    solve(i, j);
                }
            }
        }

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                arr1[i][j] += arr2[i][j];
            }
        }
        air_cleaner();
    }
    int result = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(arr1[i][j] > 0) result += arr1[i][j];
        }
    }
    cout << result << '\n';
    return 0;
}
