#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, cnt_2, cnt_5;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        cnt_2 = 0; cnt_5 = 0;
        for(int j = 2; j <= n; j *= 2) {
            cnt_2 += n / j;
        }
        for(int j = 5; j <= n; j *= 5) {
            cnt_5 += n / j;
        }
        cout << min(cnt_2, cnt_5) << '\n';
    }
}