#include <iostream>
using namespace std;
string s;
bool fun(int i, int j) {
    if( i >= j) {
        return 1;
    }
    if(s[i] == s[j]) {
        return fun(i + 1, j - 1);
    }
    else {
        return 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    bool isPal = fun(0, (int)s.length() - 1);
    cout << (isPal ? "true" : "false");
    return 0;
}
