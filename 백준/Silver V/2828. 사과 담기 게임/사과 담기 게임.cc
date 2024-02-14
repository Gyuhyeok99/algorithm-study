#include <iostream>
using namespace std;
int n, m, j, a, s, e, ret, temp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> j;
    s = 1;
    e = m;
    ret = 0;
    for(int i = 0; i < j; i++) {
        cin >> a;
        if(a >= s &&  a <= m) {
            continue;
        }
        else if(a < s) {
            temp = s - a;
            s -= temp;
            e -= temp;
            ret += temp;
        }
        else if(a > e) {
            temp = a - e;
            s += temp;
            e += temp;
            ret += temp;
        }
    }
    cout << ret << '\n';
    return 0;
}
