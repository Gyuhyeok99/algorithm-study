import java.util.*;

public class Main {

    private static int n;
    private static int[] cnt = new int[26];
    private static String s;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            s = sc.next();
            cnt[s.charAt(0) - 'a']++;
        }
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < 26; i++) {
            if(cnt[i] >= 5) {
                sb.append((char)(i + 'a'));
            }
        }
        if(sb.length() == 0) {
            System.out.println("PREDAJA");
        }
        else {
            System.out.println(sb);
        }
    }
}
