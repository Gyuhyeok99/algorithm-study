#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, s, e, ret;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> e;
        v.push_back({e, s});
    }
    sort(v.begin(), v.end());

    s = v[0].second;
    e = v[0].first;
    ret++;
    for(int i = 1; i < n; i++) {
        if(v[i].second < e) {
            continue;
        }
        s = v[i].second;
        e = v[i].first;
        ret++;
    }
    cout << ret << '\n';

    return 0;
}
