#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, l = 1, r, ret = 987654321;
vector<int> v;

bool check(int mid) {
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        cnt += v[i] / mid;
        cnt += v[i] % mid ? 1 : 0;
    }
    return n >= cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        r = max(r, temp);
    }
    sort(v.begin(), v.end());
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ret = min(mid, ret);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ret << '\n';
    return 0;
}