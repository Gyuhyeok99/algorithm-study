#include <iostream>
using namespace std;
string s;
int main() {
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 65 && s[i] < 78) {
            s[i] += 13;
        }
        else if(s[i] >= 78 && s[i] < 97) {
            s[i] -= 13;
        }
        else if(s[i] >= 97 && s[i] < 110) {
            s[i] += 13;
        }
        else if(s[i] >= 110 && s[i] < 123) {
            s[i] -= 13;
        }
    }
    cout << s;
    return 0;
}
