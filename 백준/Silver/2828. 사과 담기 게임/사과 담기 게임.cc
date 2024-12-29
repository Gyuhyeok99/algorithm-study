#include <iostream>
using namespace std;

int n, m, j, x, l, r, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> j;
    l = 1; r = m;
    for(int i = 0; i < j; i++) {
        cin >> x;
        if(x < l) {
            ret += l - x;
            r -= l - x;
            l -= l - x;

        }
        else if (x > r) {
            ret += x - r;
            l += x - r;
            r += x - r;

        }
        else {
            continue;
        }
    }
    cout << ret << '\n';
    return 0;
}