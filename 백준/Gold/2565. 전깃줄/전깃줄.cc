#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int ,int>> v;
int lis[101], len;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        auto lowerPos = lower_bound(lis, lis + len, v[i].second);
        if(*lowerPos == 0) {
            len++;
        }
        *lowerPos = v[i].second;
    }
    cout << n - len << '\n';
    return 0;
}