#include <iostream>
#include <vector>
using namespace std;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
vector<int> dragon[4][11];
int visited[101][101];
int n, ret;

void go(int y, int x, int d, int g) {
    visited[y][x] = 1;
    for(int i = 0; i <= g; i++) {
        for(int j = 0; j < dragon[d][i].size(); j++) {
            int ny = y + dy[dragon[d][i][j]];
            int nx = x + dx[dragon[d][i][j]];
            visited[ny][nx] = 1;
            y = ny;
            x = nx;
        }
    }
    return;
}
void createDragon() {
    for(int i = 0; i < 4; i++) {
        dragon[i][0].push_back(i);
        dragon[i][1].push_back((i + 1) % 4);
        for(int j = 2; j <= 10; j++) {
            int size = dragon[i][j - 1].size();
            for(int k = size - 1; k >= 0; k--) {
                dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
            }
            for(int k = 0; k < size; k++) {
                dragon[i][j].push_back((dragon[i][j - 1][k]) % 4);
            }
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    createDragon();
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        go(y, x, d, g);
    }
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(visited[i][j] && visited[i][j + 1] && visited[i + 1][j] && visited[i + 1][j + 1]) {
                ret++;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}