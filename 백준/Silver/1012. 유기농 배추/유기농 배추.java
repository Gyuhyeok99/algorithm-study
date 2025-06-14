import java.util.*;

public class Main {

    private static int[] dy = {-1, 0, 1, 0};
    private static int[] dx = {0, 1, 0, -1};
    private static class Pair {
        int y, x;
        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    private static int t, n, m, num, ret;
    private static int[][] arr, visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        while(t > 0) {
            t--;
            ret = 0;
            m = sc.nextInt();
            n = sc.nextInt();
            num = sc.nextInt();
            arr = new int[n][m];
            visited = new int[n][m];
            for(int i = 0; i < num; i++) {
                int y, x;
                x = sc.nextInt();
                y = sc.nextInt();
                arr[y][x] = 1;
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(visited[i][j] == 0 && arr[i][j] == 1) {
                        dfs(i, j);
                        ret++;
                    }
                }
            }
            System.out.println(ret);
        }
    }
    private static void dfs(int y, int x) {
        visited[y][x] = 1;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            if(visited[ny][nx] == 1 || arr[ny][nx] == 0) {
                continue;
            }
            dfs(ny, nx);
        }
    }
}
