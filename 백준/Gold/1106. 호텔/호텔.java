import java.util.*;
import java.io.*;

public class Main {

    static int[] dp;
    static int c, n, ret = Integer.MAX_VALUE;
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        c = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        dp = new int[2002];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int cost = Integer.parseInt(st.nextToken());
            int customer = Integer.parseInt(st.nextToken());
            for(int j = customer; j < dp.length; j++) {
                if (dp[j - customer] != Integer.MAX_VALUE) {
                    dp[j] = Math.min(dp[j - customer] + cost, dp[j]);
                }
            }
        }
        for(int i = c; i < dp.length; i++) {
            ret = Math.min(ret, dp[i]);
        }
        System.out.println(ret);
    }
}
