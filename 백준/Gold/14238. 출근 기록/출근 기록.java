import java.util.*;

public class Main {

    private static int num[] = new int[3];
    private static char ret[];
    private static String s;
    private static boolean[][][][][] dp = new boolean[51][51][51][3][3];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        ret = new char[s.length()];
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == 'A') {
                num[0]++;
            }
            else if(s.charAt(i) == 'B') {
                num[1]++;
            }
            else {
                num[2]++;
            }
        }
        boolean flag = solve(0, 0, 0, -1, -1);
        if(flag) {
            for(int i = 0; i < ret.length; i++) {
                System.out.print(ret[i]);
            }
        }
        else {
            System.out.print(-1);
        }
        System.out.println();
    }
    private static boolean solve(int a, int b, int c, int prev, int pprev) {
        if(a == num[0] && b == num[1] && c == num[2]) {
            return true;
        }
        if(prev >= 0 && pprev >= 0 && dp[a][b][c][prev][pprev]) {
            return false;
        }
        if(prev >= 0 && pprev >= 0) {
            dp[a][b][c][prev][pprev] = true;
        }
        if(a < num[0]) {
            ret[a + b + c] = 'A';
            if(solve(a + 1, b, c, 0, prev)) {
                return true;
            }
        }
        if(b < num[1]) {
            ret[a + b + c] = 'B';
            if(prev != 1 && solve(a, b + 1, c, 1, prev)) {
                return true;
            }
        }
        if(c < num[2]) {
            ret[a + b + c] = 'C';
            if(prev != 2 && pprev != 2 && solve(a, b, c + 1, 2, prev)) {
                return true;
            }
        }
        return false;
    }
}
