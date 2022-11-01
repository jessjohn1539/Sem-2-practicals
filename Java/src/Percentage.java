import java.util.*;
class PP{
    float M2,Phy2,Chem2,Cprog,EG,PCE;
    float percentage;
    public void get_data(float a,float b,float c,float d,float e,float f){
        M2 = a;
        Phy2 = b;
        Chem2 = c;
        Cprog = d;
        EG = e;
        PCE = f;
    }
    public void calculate(){
        percentage = ((M2+Phy2+Chem2+Cprog+EG+PCE)/400)*100;
    }
    public void display(){
        System.out.println("your SEM-2 percentage is "+percentage);
    }
}
class percentage {
    public static void main(String[] args){
        PP p = new PP();
        float q,r,s,t,u,v;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter M2 marks out of 80: ");
        q = Integer.parseInt(sc.next());
        System.out.println("Enter Phy2 marks out of 60: ");
        r = Integer.parseInt(sc.next());
        System.out.println("Enter Chem2 marks out of 60: ");
        s = Integer.parseInt(sc.next());
        System.out.println("Enter Cprogramming marks out of 60: ");
        t = Integer.parseInt(sc.next());
        System.out.println("Enter EG marks out of 60: ");
        u = Integer.parseInt(sc.next());
        System.out.println("Enter PCE marks out of 80: ");
        v = Integer.parseInt(sc.next());
        p.get_data(q,r,s,t,u,v);
        p.calculate();
        p.display();
    }
}
