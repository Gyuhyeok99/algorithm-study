#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, e, ret;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end());
    s = v[0].first;
    e = v[0].second;
    ret +=  e - s;
    for(int i = 1; i < n; i++) {
        if(e < v[i].first) {
            s = v[i].first;
            e = v[i].second;
            ret += e - s;
        }
        else {
            if(e < v[i].second) {
                ret += v[i].second - e;
                e = v[i].second;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}