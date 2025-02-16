#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBigNumbers(string a, string b) {
    string result = "";
    int carry = 0;

    while (a.size() < b.size()) a = '0' + a;
    while (b.size() < a.size()) b = '0' + b;

    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    if (carry) result += carry + '0';

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << addBigNumbers(a, b) << '\n';
    return 0;
}
