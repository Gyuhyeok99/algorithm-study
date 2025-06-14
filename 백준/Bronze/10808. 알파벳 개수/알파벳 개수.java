import java.util.*;

public class Main {

    private static int[] cnt = new int[26];
    private static String s;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        for(int i = 0; i < s.length(); i++) {
            cnt[s.charAt(i) - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            System.out.print(cnt[i] + " ");
        }
    }
}
