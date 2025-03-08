#include <iostream>
#include <cstring>
using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};
int r, c, m, ret, h = -1;
struct Shark {
    int r, c, s, d, z;
    bool die;
} shark[10001];
int temp[101][101];


void move(int idx) {
    int y = shark[idx].r;
    int x = shark[idx].c;
    int cnt = shark[idx].s;
    int dir = shark[idx].d;
    int size = shark[idx].z;
    int cycle;
    if(dir <= 1) {
        cycle = 2 * (r - 1);
    }
    else {
        cycle = 2 * (c - 1);
    }
    if(cycle > 0) {
        cnt %= cycle;
    }
    while(cnt--) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
            dir ^= 1;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        y = ny;
        x = nx;
    }
    shark[idx].r = y;
    shark[idx].c = x;
    shark[idx].d = dir;

    if(temp[y][x] != -1) {
        if(shark[temp[y][x]].z < size) {
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
    return;
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
    while(h < c) {
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
                move(i);
            }
        }
    }
    cout << ret << '\n';
    return 0;
}