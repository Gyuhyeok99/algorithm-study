#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int x;

    int count = 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        bool flag = true;
        if(x <= 1) {
            continue;
        }

        for(int j = 2; j < x; j++) {
            if(x % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
