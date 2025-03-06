#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l, idx, ret, cnt, a, b;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        if(v[i].second <= idx) {
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