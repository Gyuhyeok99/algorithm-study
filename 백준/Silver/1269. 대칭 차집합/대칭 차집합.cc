#include <iostream>
#include <map>
using namespace std;

int n , m, num, ret;
map<int, int> mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num;
        mp[num]++;
    }
    for(int i = 0; i < m; i++) {
        cin >> num;
        mp[num]++;
    }
    for(auto it : mp) {
        if(it.second == 1) {
            ret++;
        }
    }
    cout << ret << '\n';
    return 0;
}