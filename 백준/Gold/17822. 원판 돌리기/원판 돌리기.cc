#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t, x, d, k, ret;
vector<vector<int>> v(50);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            v[i].push_back(temp);
        }
    }

    while(t--) {
        cin >> x >> d >> k;

        for(int i = x; i <= n; i += x) {
            int idx = i - 1;
            if(d == 0) {
                rotate(v[idx].rbegin(), v[idx].rbegin() + k, v[idx].rend());
            }
            else {
                rotate(v[idx].begin(), v[idx].begin() + k, v[idx].end());
            }
        }

        vector<vector<int>> temp = v;
        bool flag = true;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (v[i][j] == -1) continue;
                int curr = v[i][j];

                if (v[i][(j + 1) % m] == curr) 
                    temp[i][j] = temp[i][(j + 1) % m] = -1, flag = false;
                if (v[i][(j - 1 + m) % m] == curr) 
                    temp[i][j] = temp[i][(j - 1 + m) % m] = -1, flag = false;
                if (i > 0 && v[i - 1][j] == curr) 
                    temp[i][j] = temp[i - 1][j] = -1, flag = false;
                if (i < n - 1 && v[i + 1][j] == curr) 
                    temp[i][j] = temp[i + 1][j] = -1, flag = false;
            }
        }

        v = temp;

        if (flag) {
            double sum = 0;
            double cnt = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(v[i][j] > 0) {
                        sum += v[i][j];
                        cnt++;
                    }
                }
            }

            if (cnt > 0) {  // 나누기 0 방지
                double avg = sum / cnt;
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        if(v[i][j] > 0) {  // 0 초과 값만 처리
                            if(v[i][j] > avg) v[i][j]--;
                            else if(v[i][j] < avg) v[i][j]++;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] > 0) {
                ret += v[i][j];
            }
        }
    }
    cout << ret << '\n';

    return 0;
}
