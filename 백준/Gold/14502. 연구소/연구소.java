import java.util.*;

public class Main {
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    static class Pair {
        int y, x;
        Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    static int n, m, ret;
    static int[][] arr;
    static boolean[][] visited;
    static List<Pair> virius, wall;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        virius = new ArrayList<>();
        wall = new ArrayList<>();
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[i][j] = sc.nextInt();
                if(arr[i][j] == 0) {
                    wall.add(new Pair(i, j));
                }
                else if(arr[i][j] == 2) {
                    virius.add(new Pair(i, j));
                }
            }
        }
        int cnt = wall.size();
        for(int i = 0; i < cnt; i++) {
            for(int j = i + 1; j < cnt; j++) {
                for(int k = j + 1; k < cnt; k++) {
                    arr[wall.get(i).y][wall.get(i).x] = 1;
                    arr[wall.get(j).y][wall.get(j).x] = 1;
                    arr[wall.get(k).y][wall.get(k).x] = 1;
                    ret = Math.max(ret, solve());
                    arr[wall.get(i).y][wall.get(i).x] = 0;
                    arr[wall.get(j).y][wall.get(j).x] = 0;
                    arr[wall.get(k).y][wall.get(k).x] = 0;
                }
            }
        }
        System.out.println(ret);
    }

    static int solve() {
        visited = new boolean[n][m];
        for(int i = 0; i < virius.size(); i++) {
            int y = virius.get(i).y;
            int x = virius.get(i).x;
            if(!visited[y][x]) {
                dfs(y, x);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == 0 && !visited[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    static void dfs(int y, int x) {
        visited[y][x] = true;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            if(arr[ny][nx] == 1 || visited[ny][nx]) {
                continue;
            }
            dfs(ny, nx);
        }
    }
}
