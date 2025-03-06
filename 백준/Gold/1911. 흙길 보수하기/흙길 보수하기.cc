#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l, ret, idx, cnt;
vector<pair<int, int>> v(10001);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.begin() + n);
    for(int i = 0; i < n; i++) {
        if(idx >= v[i].second) {
            continue;
        }
        if(v[i].first >= idx) {
            int temp = v[i].second - v[i].first;
            cnt = (temp / l) + (temp % l ? 1 : 0);
            idx = v[i].first + cnt * l;
        }
        else {
            int temp = v[i].second - idx;
            cnt = (temp / l) + (temp % l ? 1 : 0);
            idx = idx + cnt * l;
        }
        ret += cnt;
    }
    cout << ret << '\n';
    return 0;
}