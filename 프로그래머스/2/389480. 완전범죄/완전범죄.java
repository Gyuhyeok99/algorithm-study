class Solution {
    static int maxA, savedA;
    static int[] dp;
    public int solution(int[][] info, int n, int m) {
        int answer = 0;
        for (int i = 0; i < info.length; i++) {
            maxA += info[i][0];
        }
        dp = new int[m];
        for (int i = 0; i < info.length; i++) {
            int a = info[i][0];
            int b = info[i][1];
            for (int j = m - 1; j >= b; j--) {
                dp[j] = Math.max(dp[j], dp[j - b] + a);
            }
        }
        for (int i = 0; i < m; i++) {
            savedA = Math.max(savedA, dp[i]);
        }
        if(maxA - savedA >= n) {
            answer = -1;
        }
        else {
            answer = maxA - savedA;
        }
        return answer;
    }
}