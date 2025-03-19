#include <iostream>
#include <map>
using namespace std;

int n , m, ret;
map<string, int> mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s] = 1;
    }
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if(mp[s] == 1) {
            ret++;
        }
    }
    cout << ret << '\n';
    return 0;
}