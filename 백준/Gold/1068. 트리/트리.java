import java.util.*;

public class Main {

    static int n, m, root, ret;
    static List<List<Integer>> tree = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            tree.add(new ArrayList<>());
        }
        for(int i = 0; i < n; i++) {
            int num = sc.nextInt();
            if(num != -1) {
                tree.get(num).add(i);
            }
            else {
                root = i;
            }
        }
        m = sc.nextInt();
        if(m == root) {
            System.out.println(0);
        }
        else {
            System.out.println(dfs(root));
        }
    }
    static int dfs(int here) {
        int ret = 0;
        int child = 0;
        for(int there : tree.get(here)) {
            if(there == m) {
                continue;
            }
            ret += dfs(there);
            child++;
        }
        if(child == 0) {
            return 1;
        }
        return ret;
    }
}
