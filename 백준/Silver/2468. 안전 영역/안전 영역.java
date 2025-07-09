import java.util.*;

public class Main {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int n, cnt, ret = 1;
    static int[][] a;
    static boolean[][] visited;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        for(int i = 1; i <= 100; i++) {
            visited = new boolean[n][n];
            cnt = 0;
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(a[j][k] > i && !visited[j][k]) {
                        dfs(j, k, i);
                        cnt++;
                    }
                }
            }
            ret = Math.max(ret, cnt);
        }
        System.out.println(ret);
    }
    static void dfs(int y, int x, int h) {
        visited[y][x] = true;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) {
                continue;
            }
            if(a[ny][nx] <= h || visited[ny][nx]) {
                continue;
            }
            dfs(ny, nx, h);
        }
    }
}
