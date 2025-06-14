import java.util.*;

public class Main {

    private static int n;
    private static String patten;
    private static String s;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        patten = sc.next();
        String[] temp = patten.split("\\*");
        String preffix = temp[0];
        String suffix = temp[1];
        for(int i = 0; i < n; i++) {
            s = sc.next();
            if(s.length() >=(preffix.length() + suffix.length())
                    && s.substring(0, preffix.length()).equals(preffix)
                    && s.substring(s.length() - suffix.length()).equals(suffix)) {
                System.out.println("DA");
            }
            else {
                System.out.println("NE");
            }
        }
    }
}
