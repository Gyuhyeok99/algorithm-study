#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};
struct Shark {
    int y, x, s, d, z;
    bool die;
} shark[10001];
int r, c, m, ret;
int arr[101][101], temp[101][101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> m;

    for(int i = 1; i <= m; i++) {
        int y, x, s, d, z;
        cin >> y >> x >> s >> d >> z;
        y--, x--, d--;
        shark[i].y = y; shark[i].x = x; shark[i].s = s; shark[i].d = d; shark[i].z = z;

        if(shark[i].d <= 1) {
            shark[i].s %= (2 * (r - 1));
        }
        else {
            shark[i].s %= (2 * (c - 1));
        }
        arr[y][x] = i;
    }

    for(int t = 0; t < c; t++) {
        for(int y = 0; y < r; y++) {
            if(arr[y][t]) {
                shark[arr[y][t]].die = true;
                ret += shark[arr[y][t]].z;
                arr[y][t] = 0;
                break;
            }
        }
        memset(temp, 0, sizeof(temp));
        for(int i = 1; i <= m; i++) {
            if(shark[i].die){
                continue;
            }
            int y = shark[i].y;
            int x = shark[i].x;
            int s = shark[i].s;
            int d = shark[i].d;
            int ny, nx;
            while(s--) {
                ny = y + dy[d];
                nx = x + dx[d];
                if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
                    d ^= 1;
                    ny = y + dy[d];
                    nx = x + dx[d];
                }
                y = ny;
                x = nx;
            }
            shark[i].y = y;
            shark[i].x = x;
            shark[i].d = d;

            if(temp[y][x]) {
                if(shark[temp[y][x]].z < shark[i].z) {
                    shark[temp[y][x]].die = true;
                    temp[y][x] = i;
                }
                else {
                    shark[i].die = true;
                }
            }
            else {
                temp[y][x] = i;
            }
        }
        memcpy(arr, temp, sizeof(arr));
    }
    cout << ret << '\n';
    return 0;
}