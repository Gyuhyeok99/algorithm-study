import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuffer sb = new StringBuffer();
        String before, after;
        sb.append(sc.next());
        before =  sb.toString();
        after = sb.reverse().toString();
        if(before.equals(after)) {
            System.out.println(1);
        }
        else {
            System.out.println(0);
        }
    }
}
