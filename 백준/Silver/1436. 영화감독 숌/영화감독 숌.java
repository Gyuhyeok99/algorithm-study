import java.util.*;

public class Main {

    static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int i = 666;
        while(true) {
            if(Integer.toString(i).contains("666")) {
                n--;
            }
            if(n == 0) {
                break;
            }
            i++;
        }
        System.out.println(i);
    }
}
