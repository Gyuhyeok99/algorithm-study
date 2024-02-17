#include <iostream>
#include <map>
#include <cstdlib>
using namespace std;

int n, m;
string s[100004];
string a;
map<string, int> mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        mp[s[i]] = i;
    }

    for(int i = 0; i < m; i++) {
        cin >> a;
        if(atoi(a.c_str())) {
            cout << s[atoi(a.c_str())] << '\n';
        }
        else {
            cout << mp[a] << '\n';
        }
    }

}