#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    int five = n / 5;
    int remain = n % 5;
    int three = remain / 3;
    while(remain % 3 != 0) {
        five--;
        if(five < 0) {
            cout << -1 << '\n';
            return 0;
        }
        remain += 5;
        three = remain / 3;
    }
    cout << five + three << '\n';
    return 0;
}
