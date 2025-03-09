#include <iostream>
#include <map>
using namespace std;

int x, n, m, ret;
int a[1001], b[1001], aSum[2002], bSum[2002];
map<int, int> aCnt, bCnt;

void make(int t, int psum[], map<int, int>& mp) {
    for(int i = 1; i <= t; i++) {
        for(int j = i; j < t + i; j++) {
            int sum = psum[j] - psum[j - i];
            mp[sum]++;
            if(i == t) {
                break;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> x;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for(int i = 1; i <= n; i++) {
        aSum[i] = aSum[i - 1] + a[i - 1];
    }
    for(int i = 1; i <= m; i++) {
        bSum[i] = bSum[i - 1] + b[i - 1];
    }

    for(int i = n + 1; i <= 2 * n; i++) {
        aSum[i] = aSum[i - 1] + a[i - 1 - n];
    }
    for(int i = m + 1; i <= 2 * m; i++) {
        bSum[i] = bSum[ i -1] + b[i - 1 - m];
    }

    make(n, aSum, aCnt);
    make(m, bSum, bCnt);
    ret += (aCnt[x] + bCnt[x]);
    for(int i = 1; i < x; i++) {
        ret += (aCnt[i] * bCnt[x - i]);
    }
    cout << ret << '\n';
    return 0;
}