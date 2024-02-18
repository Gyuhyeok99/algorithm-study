#include <iostream>
#include <string.h>
using namespace std;
const int max_n = 101;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, w;
    int a[max_n][max_n];
    string s;
    cin >> h >> w;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < h; i++) {
        cin >> s;
        for(int j = 0; j < w; j++){
            if(s[j] != 'c') {
                a[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(a[i][j] == 0) {
                int cnt = 1;
                while(a[i][j + 1] == -1) {
                    a[i][j + 1] = cnt++;
                    j++;
                }
            }
        }
    }
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
