#include <iostream>
#include <vector>
using namespace std;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
struct A {
    int m, s, d;
};
int n, m, k, ret;
vector<A> v[51][51], temp[51][51], temp2[51][51];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int y, x, mm, s, d;
        cin >> y >> x >> mm >> s >> d;
        y--, x--;
        v[y][x].push_back({mm, s, d});
    }
    while(k--) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                temp[i][j].clear();
                temp2[i][j].clear();
            }
        } 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j].size()) {
                    for(auto aa : v[i][j]) {
                        int dir = aa.d;
                        int ny = (i + dy[dir] * aa.s % n + n * 1000) % n;
                        int nx = (j + dx[dir] * aa.s % n + n * 1000) % n;
                        temp[ny][nx].push_back({aa.m, aa.s, dir});
                    }

                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(temp[i][j].size() == 1) {
                    temp2[i][j].push_back(temp[i][j][0]);
                }
                else if(temp[i][j].size() >= 2) {
                    int sum = 0; int flag = 0, vSum = 0;
                    for(auto aa : temp[i][j]) {
                        sum += aa.m;
                        vSum += aa.s;
                        if(aa.d % 2 == 0) {
                            flag |= (1 << 0);
                        }
                        else {
                            flag |= (1 << 2);
                        }
                    }
                    if(sum < 5) {
                        continue;
                    }
                    else {
                        int ss = sum / 5;
                        int vv = vSum / temp[i][j].size();
                        if(flag == 3) {
                            for(int ii = 0; ii < 4; ii++) {
                                temp2[i][j].push_back({ss, vv, 2 * ii + 1});
                            }
                        }
                        else {
                            for(int ii = 0; ii < 4; ii++) {
                                temp2[i][j].push_back({ss, vv, 2 * ii});
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                v[i][j] = temp2[i][j];  
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j].size()) {
                for(auto aa : v[i][j]) {
                    ret += aa.m;
                }
            }
        } 
    }
    cout << ret << '\n';
    return 0;
}