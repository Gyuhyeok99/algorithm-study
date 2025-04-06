#include <iostream>
#include <map>
using namespace std;

int s, m, n, ret;
int a[1001], b[1001], aSum[2002], bSum[2002];
map<int, int> aCnt, bCnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < n; i++) {
        cin >> b[i];
    }

    for(int i = 1; i <= m; i++) {
        aSum[i] = aSum[i - 1] + a[i - 1];
    }
    for(int i = m + 1; i <= 2 * m; i++) {
        aSum[i] = aSum[i - 1] + a[i - 1 - m];
    }

    for(int i = 1; i <= n; i++) {
        bSum[i] = bSum[i - 1] + b[i - 1];
    }
    for(int i = n + 1; i <= 2 * n; i++) {
        bSum[i] = bSum[i - 1] + b[i - 1 - n];
    }

    for(int i = 1; i <= m; i++) {
        for(int j = i; j <= m + i - 1; j++) {
            int sum = aSum[j] - aSum[j - i];
            aCnt[sum]++;
            if(i == m) {
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n + i - 1; j++) {
            int sum = bSum[j] - bSum[j - i];
            bCnt[sum]++;
            if(i == n) {
                break;
            }
        }
    }

    ret = aCnt[s] + bCnt[s];
    for(int i = 1; i < s; i++) {
        ret += aCnt[i] * bCnt[s - i];
    }
    cout << ret << '\n';

    return 0;
}