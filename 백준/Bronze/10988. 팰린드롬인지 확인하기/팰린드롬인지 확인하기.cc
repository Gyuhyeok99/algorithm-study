#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    string temp = s;
    reverse(s.begin(), s.end());
    if(s == temp) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }
    return 0;
}
