#include <iostream>
using namespace std;

int arr[101];
int a, b, c, sum;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++) {
        int start, end;
        cin >> start >> end;
        for(int j = start; j < end; j++) {
            arr[j]++;
        }
    }
    for(int x : arr) {
        if(x == 1) {
            sum += a;
        }
        else if (x == 2) {
            sum += 2 * b;
        }
        else if (x == 3) {
            sum += 3 * c;
        }
    }
    cout << sum;
    return 0;
}