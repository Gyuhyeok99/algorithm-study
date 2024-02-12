#include <iostream>
using namespace std;
int n;
int main() {

    while(cin >> n) {
        int cnt = 1, ret = 1;
        while(true) {
            if(cnt % n == 0) {
                cout << ret << '\n';
                break;
            }
            else {
                cnt = (10 * cnt) + 1;
                cnt %= n;
                ret++;
            }
        }
    }
    return 0;
}
