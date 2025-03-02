#include <iostream>
#include <algorithm>

using namespace std;

int n, l, r, ret, sum;
vector<int> v;
bool check[4000001];


void isPrime(int num) {
    for(int i = 2; i <= num; i++) {
        if(check[i]) {
            continue;
        }
        for(int j = 2 * i; j <= num; j += i) {
            check[j] = 1;
        }
    }

    for(int i = 2; i <= num; i++) {
        if(check[i] == 0) {
            v.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    isPrime(n);

    while(1) {
        if(sum >= n) {
            sum -= v[l++];
        }
        else if(r == v.size()) {
            break;
        }
        else {
            sum += v[r++];
        }
        if(sum == n) {
            ret++;
        }
    }
    cout << ret << '\n';
    return 0;
}