#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int n, k, l, x, t, d;
char c;
int arr[101][101];
deque<pair<int, int>> v;
queue<pair<int, char>> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        arr[y - 1][x - 1] = 1;
    }

    cin >> l;
    for(int i = 0; i < l; i++) {
        cin >> x >> c;
        q.push({x, c});
    }

    v.push_back({0, 0});
    while(1) {
        int hy = v.front().first;
        int hx = v.front().second;

        int ny = hy + dy[d % 4];
        int nx = hx + dx[d % 4];

        if(ny < 0 || nx < 0 || ny >= n || nx >= n) {
            break;
        }
        for(auto a : v) {
            if(a.first == ny && a.second == nx) {
                goto end;
            }
        }

        v.push_front({ny, nx});

        if(arr[ny][nx] == 1) {
            arr[ny][nx] = 0;
        }
        else {
            v.pop_back();
        }

        t++;
        if(q.size() && t == q.front().first) {
            if(q.front().second == 'D') {
                d++;
            }
            else {
                d += 3;
            }
            q.pop();
        }
    }
    end:
    cout << t + 1 << '\n';
    return 0;
}