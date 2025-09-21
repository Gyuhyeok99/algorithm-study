#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<int> set;

bool isChecked(int num) {
    if (num <= 1) return false;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    do {
        int x = 0;
        for (char number : numbers) {
            x = x * 10 + (number - '0');
            set.insert(x);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));

    for (int it : set) {
        if (isChecked(it)) {
            answer++;
        }
    }
    return answer;
}