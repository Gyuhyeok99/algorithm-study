import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int cnt = 0;  
        while (n >= 0) {
            if (n % 5 == 0) {
                cnt += n / 5;
                System.out.println(cnt);
                return;
            }
            n -= 3;
            cnt++; 
        }
        System.out.println(-1);
    }
}
