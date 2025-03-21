#include <iostream>
using namespace std;

int n, l, ret;
int a[101][101], b[101][101];

void solve(int x[101][101]) {
    for(int i = 0; i < n; i++) {
        int cnt = 1;
        int j;
        for(j = 0; j < n - 1; j++) {
            if(x[i][j] == x[i][j + 1]) {
                cnt++;
            }
            else if(x[i][j] + 1 == x[i][j + 1] && cnt >= l) {
                cnt = 1;
            }
            else if(x[i][j] - 1 == x[i][j + 1] && cnt >= 0) {
                cnt = -l + 1;
            }
            else {
                break;
            }
        }
        if(j == n - 1 && cnt >= 0) {
            ret++;
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }

    solve(a);
    solve(b);
    cout << ret << '\n';
    return 0;
}