#include <iostream>
#include <string>
using namespace std;

string s;
int cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(i + 2 != s.size()) {
            string temp = s.substr(i, 3);
            if (temp == "dz=") {
                cnt++;
                i += 2;
                continue;
            }
        }
        if(i + 1 != s.size()) {
            string temp = s.substr(i, 2);
            if(temp == "c=" || temp == "c-" || temp == "d-" || temp == "lj"
            || temp == "nj" || temp == "s=" || temp == "z=") {
                cnt++;
                i++;
                continue;
            }
        }
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}