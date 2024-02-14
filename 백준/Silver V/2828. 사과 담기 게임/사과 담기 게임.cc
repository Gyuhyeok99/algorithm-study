#include <iostream>
using namespace std;
int n, m, j, a, s, e, ret;
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
            while(a != s) {
                s--; e--;
                ret++;
            }
            continue;
        }
        else if(a > e) {
            while(a != e) {
                s++; e++;
                ret++;
            }
            continue;
        }
    }
    cout << ret << '\n';
    return 0;
}
