#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, s, t, ret;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> t;
        v.push_back({s, t});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        ret = max(ret, v[i].first);
        ret += v[i].second;
    }
    cout << ret << '\n';

    return 0;
}
