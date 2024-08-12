#include <iostream>
using namespace std;

int n;
string p, s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    cin >> p;
    auto it = p.find("*");
    string prefix = p.substr(0, it);
    string suffix = p.substr(it + 1);
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(s.size() < prefix.size() + suffix.size()) {
            cout << "NE" << '\n';
            continue;
        }
        if(s.substr(0, prefix.size()) == prefix && s.substr(s.size() - suffix.size()) == suffix) {
            cout << "DA" << '\n';
        }
        else {
            cout << "NE" << '\n';
        }
    }
    return 0;
}