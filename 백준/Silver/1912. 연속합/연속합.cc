#include <iostream>
#include <algorithm>
using namespace std;

int n, sum, ret = -987654321;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i  = 0; i < n; i++) {
        int temp;
        cin >> temp;
        sum += temp;
        ret = max(ret, sum);
        if(sum < 0) {
            sum = 0;
        }
    }
    cout << ret << '\n';
    return 0;
}