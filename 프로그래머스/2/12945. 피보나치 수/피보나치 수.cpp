#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[100001];
int solve(int n) {
    if(n < 0) {
        return 0;
    }
    int& ret = dp[n];
    if(ret != -1) {
        return ret;
    }
    return ret = (solve(n - 2) + solve(n - 1)) % 1234567;
}
int solution(int n) {
    int answer = 0;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    answer = solve(n);
    return answer;
}