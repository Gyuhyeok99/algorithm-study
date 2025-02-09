#include <iostream>
using namespace std;

int n, m, ret, a[5][5];
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < (1 << (n * m)); i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            int cur = 0;
            for(int k = 0; k < m; k++) {
                int x = j * m + k;
                if (((i & (1 << x))) == 0)  {
                    cur = cur * 10 + a[j][k];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        for(int j = 0; j < m; j++) {
            int cur = 0;
            for(int k = 0; k < n; k++) {
                int x = k * m + j;
                if(((i & (1 << x))) != 0) {
                    cur = cur * 10 + a[k][j];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ret = max(ret, sum);
    }
    cout << ret << '\n';
    return 0;
}