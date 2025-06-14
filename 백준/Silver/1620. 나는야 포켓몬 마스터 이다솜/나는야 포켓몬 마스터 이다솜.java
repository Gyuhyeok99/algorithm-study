import java.util.*;

public class Main {

    private static int n, m;
    private static Map<String, Integer> mp1 = new HashMap<>();
    private static Map<Integer, String> mp2 = new HashMap<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for(int i = 1; i <= n; i++) {
            String s = sc.next();
            mp1.put(s, i);
            mp2.put(i, s);
        }
        for(int i = 0; i < m; i++) {
            String s = sc.next();
            if(s.matches("\\d+")) {
                System.out.println(mp2.get(Integer.parseInt(s)));
            }
            else {
                System.out.println(mp1.get(s));
            }
        }
    }
}
