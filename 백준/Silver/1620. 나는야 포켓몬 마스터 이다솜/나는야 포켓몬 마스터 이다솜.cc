#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    string v[100004];
    std::map<string, int> m2;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        v[i] = s;
        m2[s] = i;
    }
    string r;
    for(int i = 0; i < m; i++) {
        cin >> r;
        if(atoi(r.c_str())) {
            cout << v[atoi(r.c_str())] << '\n';
        }
        else {
            cout << m2[r] << '\n';
        }
    }
    return 0;
}
