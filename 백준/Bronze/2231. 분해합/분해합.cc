#include <iostream>
using namespace std;

int main() {
   int n;
   cin >> n;
   bool flag = true;
   for(int i = 1; i < n; i++) {
       int temp = i;
       int sum = i;
       while (temp > 0) {
           sum += temp % 10;
           temp /= 10;
       }
       if(sum == n) {
           cout << i << endl;
           flag = false;
           break;
       }
   }
   if(flag) {
       cout << 0 << endl;
   }
    return 0;
}
