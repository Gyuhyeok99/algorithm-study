#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int j = 0; j < t; j++) {
        string quiz;
        cin >> quiz;
        int sum = 0;
        int count = 1;
        for (int i = 0; i < quiz.length(); i++) {
            if (quiz[i] == 'O') {
                sum += count;
                count++;
            } else {
                count = 1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
