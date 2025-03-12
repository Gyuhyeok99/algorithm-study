#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n, m, ret;
int a[20001], b[20001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        ret = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(b, b + m);
        for(int i : a) {
            ret += lower_bound(b, b + m, i) - b;
        }
        cout << ret << '\n';
    }
    return 0;
}