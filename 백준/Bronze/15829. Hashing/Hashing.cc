#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int arr[50];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        arr[i] = s[i] - 96;
        sum += arr[i] * pow(31, i);
    }
    int result  = sum % 1234567891;
    cout << result << endl;
    return 0;
}
