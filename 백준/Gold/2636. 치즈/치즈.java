import java.util.*;

public class Main {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static int n, m, t, cnt;
    static int[][] arr;
    static boolean[][] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        while(true) {
            visited = new boolean[n][m];
            cnt = 0;
            dfs(0, 0);
            boolean flag= true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(arr[i][j] == 1) {
                        flag = false;
                        break;
                    }
                }
            }
            t++;
            if(flag) {
                break;
            }
        }
        System.out.println(t);
        System.out.println(cnt);
    }
    static void dfs(int y, int x) {
        visited[y][x] = true;
        if(arr[y][x] == 1) {
            arr[y][x] = 0;
            cnt++;
            return;
        }
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            if(visited[ny][nx]) {
                continue;
            }
            dfs(ny, nx);
        }
    }
}
