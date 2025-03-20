#include <string>
#include <vector>

using namespace std;

long long dp[2001];
long long solve(int idx, int n) {
    if(idx > n) {
        return 0;
    }
    if(idx == n) {
        return 1;
    }
    long long & ret = dp[idx];
    
    if(ret) {
        return ret;
    }

    ret += (solve(idx + 1, n) + solve(idx + 2, n) ) % 1234567;
    return ret;
}
long long solution(int n) {
    long long answer = 0;

    answer = solve(0, n);
    return answer;
}