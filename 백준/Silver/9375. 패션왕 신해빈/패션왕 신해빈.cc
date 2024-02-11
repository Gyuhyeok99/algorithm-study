#include <iostream>
#include <map>
using namespace std;
int main() {

    string a, b;
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++) {
        map<string, int> mp;
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> a >> b;
            if(mp.find(b) != mp.end()) {
                mp[b]++;
            }
            else {
                mp[b] = 1;
            }
        }
        int x = 1;
        for(const auto& pair : mp) {
            x *= pair.second + 1;
        }
        cout << x - 1<< '\n';
    }
    return 0;
}
