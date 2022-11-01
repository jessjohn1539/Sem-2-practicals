import java.util.*;
class circle{
    int rad;
    double area;
    public void get_data(int r){
        rad = r;
    }
    public void calculate(){
        area = 3.14*rad*rad;
    }
    public void display(){
        System.out.println("Area is "+area);
    }
}
class demo{
    public static void main(String[] args){
        circle c = new circle();
        int x;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of radius: ");
        x = Integer.parseInt(sc.next());
        c.get_data(x);
        c.calculate();
        c.display();
    }
}
