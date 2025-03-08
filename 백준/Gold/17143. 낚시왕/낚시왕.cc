#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int r, c, m, h = -1, ret;
struct Shark {
    int r, c, s, d, z;
    bool die;
};
int temp[101][101];
Shark shark[10001];

void move(Shark& s, int idx) {
    int cnt = s.s;
    int y = s.r; int x = s.c;
    int cycle = 0;
    if(s.d <= 1) {
        cycle = 2 * (r - 1);
    }
    else {
        cycle = 2 * (c - 1);
    }
    if(cycle > 0) {
        cnt %= cycle;
    }
    while(cnt--) {
        int ny = y + dy[s.d];
        int nx = x + dx[s.d];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
            s.d = s.d ^ 1;
            ny = y + dy[s.d];
            nx = x + dx[s.d];
        }
        y = ny;
        x = nx;
    }
    s.r = y;
    s.c = x;
    if(temp[y][x] != -1) {
        if(shark[temp[y][x]].z < shark[idx].z) {
            shark[temp[y][x]].die = true;
            temp[y][x] = idx;
        }
        else {
            shark[idx].die = true;
        }
    }
    else {
        temp[y][x] = idx;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> m;
    for(int i = 0; i < m; i++) {
        cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;
        shark[i].r--;
        shark[i].c--;
        shark[i].d--;
    }
    while(h <= c - 1) {
        h++;
        bool flag = false;
        for(int i = 0; i < r; i++) {
            if(flag) {
                break;
            }
            for(int j = 0; j < m; j++) {
                if(!shark[j].die && shark[j].r == i && shark[j].c == h) {
                    ret += shark[j].z;
                    shark[j].die = true;
                    flag = true;
                    break;
                }
            }
        }
        memset(temp, -1, sizeof(temp));
        for(int i = 0; i < m; i++) {
            if(!shark[i].die) {
                move(shark[i], i);
            }
        }
    }
    cout << ret << '\n';
    return 0;
}
