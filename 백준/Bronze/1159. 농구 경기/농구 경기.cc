#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int a[26];
string s[151];
int n;
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(a, 0, sizeof(a));

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        a[s[i][0] - 'a']++;
    }
    vector<char> v;
    for(int i = 0; i < 26; i++) {
        if(a[i] >= 5) {
            v.push_back(i + 'a');
        }
    }
    if(v.size() == 0) {
        cout << "PREDAJA" << '\n';
    }
    else {
        for (char c: v) {
            cout << c;
        }
    }
}
