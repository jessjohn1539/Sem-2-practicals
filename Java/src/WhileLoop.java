import java.util.*;
public class WhileLoop {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter numbers to be printed: ");
        n = Integer.parseInt(sc.next());
        int i=0;
        while(i<=n){
            System.out.println(i);
            i++;
        }
    }
}
