#include <iostream>
using namespace std;

int n, m, s, e;
int arr[2001], dp[2001][2001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] == arr[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(arr[j] == arr[j + i] && dp[j + 1][j + i - 1]) {
                dp[j][j + i] = 1;
            }
        }
    }

    cin >> m;
    while(m--) {
        cin >> s >> e;
        s--, e--;
        cout << dp[s][e] << '\n';
    }
    return 0;
}