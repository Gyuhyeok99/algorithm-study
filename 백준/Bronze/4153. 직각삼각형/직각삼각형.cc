#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    while(1) {
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
            return 0;
        }

        sort(arr, arr + 3);

        if (pow(arr[0], 2) + pow(arr[1], 2) == pow(arr[2], 2)) {
            cout << "right" << endl;
        } else {
            cout << "wrong" << endl;
        }
    }
}
