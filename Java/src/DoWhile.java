import java.util.*;
public class DoWhile {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter numbers to be printed: ");
        n = Integer.parseInt(sc.next());
        int i=0;
        do{
            System.out.println(i);
            i++;
        }while(i<=n);
    }
}
