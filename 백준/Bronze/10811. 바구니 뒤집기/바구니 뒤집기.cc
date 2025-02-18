#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        reverse(v.begin() + a - 1, v.begin() + b);
    }
    for(int i : v) {
        cout << i << ' ';
    }
    return 0;
}