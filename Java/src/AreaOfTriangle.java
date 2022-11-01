import java.util.*;
class triangle{
    int height, base;
    double area;
    public void get_data(int h, int b){
        height = h;
        base = b;
    }
    public void calculate(){
        area = (height*base)/2;
    }
    public void display(){
        System.out.println("Area of triangle is "+area);
    }
}
public class AreaOfTriangle {
    public static void main(String[] args){
        triangle c = new triangle();
        int x, y;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of height: ");
        x = Integer.parseInt(sc.next());
        System.out.println("Enter the value of base: ");
        y = Integer.parseInt(sc.next());
        c.get_data(x,y);
        c.calculate();
        c.display();
    }
}
