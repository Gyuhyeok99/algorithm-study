#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, l = 1, r, ret = 987654321;
vector<int> v;

bool check(int mid) {
    int j = 0;
    for(int i  = 0; i < m; i++) {
        int sum = 0;
        while(j < v.size()) {
            if(sum + v[j] > mid) {
                break;
            }
            sum += v[j];
            j++;
        }
    }
    return j == v.size();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        r += temp;
    }
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ret = min(ret, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ret << '\n';
    return 0;
}