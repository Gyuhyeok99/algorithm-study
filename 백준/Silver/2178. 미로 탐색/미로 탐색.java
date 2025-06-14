import java.util.*;

public class Main {

    public static class Pair {
        int y, x;
        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    private static int n, m;
    private static int[][] arr;
    private static int[] dy = {1, 0, -1, 0};
    private static int[] dx = {0, 1, 0, -1};
    private static int[][] visited;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[n][m];
        visited = new int[n][m];
        for(int i = 0; i < n; i++) {
            String s = sc.next();
            char[] c = s.toCharArray();
            for(int j = 0; j < m; j++) {
                arr[i][j] = c[j] - '0';
            }
        }
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(0, 0));
        visited[0][0] = 1;
        while(!queue.isEmpty()) {
            Pair pair = queue.remove();
            for(int i = 0; i < 4; i++) {
                int ny = pair.y + dy[i];
                int nx = pair.x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                    continue;
                }
                if(visited[ny][nx] >= 1 || arr[ny][nx] == 0) {
                    continue;
                }
                visited[ny][nx] = visited[pair.y][pair.x] + 1;
                queue.offer(new Pair(ny, nx));
            }
        }
        System.out.println(visited[n - 1][m - 1]);
    }
}
