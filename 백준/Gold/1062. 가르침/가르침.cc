#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, mask, ret;
string s[51];
vector<int> v;

int go(int m) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        bool flag = true;
        for(int j = 4; j < s[i].size(); j++) {
            if(!(m & (1 << s[i][j] - 'a'))) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cnt++;
        }
    }
    return cnt;
}
void solve(int idx, int selected, int m) {
    if(selected == k - 5) {
        ret = max(ret, go(m));
        return;
    }

    for(int i = idx; i < v.size(); i++) {
        solve(i + 1, selected + 1, m | (1 << v[i]));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    mask |= (1 << ('a' - 'a'));
    mask |= (1 << ('n' - 'a'));
    mask |= (1 << ('t' - 'a'));
    mask |= (1 << ('i' - 'a'));
    mask |= (1 << ('c' - 'a'));

    cin >> n >> k;



    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 4; j < s[i].size() - 4; j++) {
            int bit = s[i][j] - 'a';
            if(!(mask & (1 << bit))) {
                if(find(v.begin(), v.end(), bit) == v.end()) {
                    v.push_back(bit);
                }
            }
        }
    }

    if(k < 5) {
        cout << 0 << '\n';
        return 0;
    }

    if(v.size() <= k - 5) {
        cout << n << '\n';
        return 0;
    }

    solve(0, 0, mask);
    cout << ret << '\n';
    return 0;
}