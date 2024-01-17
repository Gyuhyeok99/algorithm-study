#include <iostream>
#include <map>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, int> map;
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        map[x]++;
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> x;
         auto it = map.find(x);
         if(it != map.end()) {
             cout << it->second << ' ';
         }
         else {
             cout << 0 << ' ';
         }
    }

    return 0;
}
