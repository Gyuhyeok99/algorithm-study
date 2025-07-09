import java.util.*;

public class Main {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int t, m, n, k, ret;
    static int[][] a;
    static boolean[][] visited;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        while(t > 0) {
            t--;
            ret = 0;
            m = sc.nextInt();
            n = sc.nextInt();
            k = sc.nextInt();
            a = new int[n][m];
            visited = new boolean[n][m];
            for(int i = 0; i < k; i++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                a[y][x] = 1;
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(!visited[i][j] && a[i][j] == 1) {
                        ret++;
                        dfs(i, j);
                    }
                }
            }
            System.out.println(ret);
        }
    }
    static void dfs(int y, int x) {
        visited[y][x] = true;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            if(a[ny][nx] == 0 || visited[ny][nx]) {
                continue;
            }
            dfs(ny, nx);
        }
    }
}
