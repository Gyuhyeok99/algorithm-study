#include <iostream>

#define M 1234567891
using namespace std;

int main() {

    int n;
    cin >> n;
    long long hash = 0, r = 1;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        hash = (hash + (s[i] - 'a' + 1) * r ) % M;
        r = (r * 31) % M;
    }
    cout << hash << endl;

}
