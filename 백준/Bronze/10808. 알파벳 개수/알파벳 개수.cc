#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int a[26];
int main() {
    memset(a, 0, sizeof(a));
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        a[s[i] - 97]++;
    }
    for(int i = 0; i < 26; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
