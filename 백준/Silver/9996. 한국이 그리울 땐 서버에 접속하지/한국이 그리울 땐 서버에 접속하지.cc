#include <iostream>
using namespace std;
int n;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    cin >> s;
    int idx = s.find('*');
    string prefix = s.substr(0, idx);
    string suffix = s.substr(idx + 1);

    for(int i = 0; i < n; i++) {
        string q;
        cin >> q;
        if(prefix.size() + suffix.size() > q.size()) {
            cout << "NE" << '\n';
        }
        else {
            if (q.substr(0, prefix.size()) == prefix
                && q.substr(q.size() - suffix.size()) == suffix) {
                cout << "DA" << '\n';
            } else {
                cout << "NE" << '\n';
            }
        }
    }
    return 0;
}
