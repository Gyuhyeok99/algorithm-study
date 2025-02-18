#include <iostream>
using namespace std;

string s[5];
int a[5][15];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 5; i++) {
        cin >> s[i];
        for(int j = 0; j < s[i].size(); j++) {
            a[i][j] = 1;
        }
    }
    for(int j = 0; j < 15; j++) {
        for(int i = 0; i < 5; i++) {
            if(a[i][j]) {
                cout << s[i][j];
            }
        }
    }
    return 0;
}