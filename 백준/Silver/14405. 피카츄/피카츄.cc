#include <iostream>
#include <algorithm>
using namespace std;

string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    bool flag = true;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'p') {
            if((i + 1) != s.size() && s[i + 1] == 'i') {
                i++;
            }
            else {
                flag = false;
                break;
            }
        }
        else if(s[i] == 'k') {
            if((i + 1) != s.size() && s[i + 1] == 'a') {
                i++;
            }
            else {
                flag = false;
                break;
            }
        }
        else if(s[i] == 'c') {
            if((i + 2) != s.size() && s[i + 1] == 'h' && s[i + 2] == 'u') {
                i += 2;
            }
            else {
                flag = false;
                break;
            }
        }
        else {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
    return 0;
}