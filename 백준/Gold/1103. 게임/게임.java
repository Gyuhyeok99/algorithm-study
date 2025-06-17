import java.util.*;
import java.io.*;

public class Main {

    static int dy[] = {-1, 0, 1, 0};
    static int dx[] = {0, 1, 0, -1};
    static int n, m;
    static int[][] arr, dp;
    static boolean[][] visited;
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        arr = new int[51][51];
        visited = new boolean[51][51];
        dp = new int[51][51];
        for(int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            for(int j = 0; j < m; j++) {
                if(s.charAt(j) == 'H') {
                    arr[i][j] = -1;
                }
                else {
                    arr[i][j] = s.charAt(j) - '0';
                }
            }
        }
        System.out.println(solve(0, 0));
    }

    static int solve(int y, int x) {
        if(y < 0 || x < 0 || y >= n || x >= m || arr[y][x] == -1) {
            return 0;
        }
        if(visited[y][x]) {
            System.out.println(-1);
            System.exit(0);
        }

        int ret = dp[y][x];
        if(ret != -1) {
            return ret;
        }
        visited[y][x] = true;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i] * arr[y][x];
            int nx = x + dx[i] * arr[y][x];
            ret = Math.max(ret, solve(ny, nx) + 1);
        }
        visited[y][x] = false;
        dp[y][x] = ret;
        return ret;
    }
}
