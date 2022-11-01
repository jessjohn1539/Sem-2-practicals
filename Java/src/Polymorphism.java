class Student {
    String name;
    int age;

    public void PrintInfo(String name) {
        System.out.println(name);
    }

    public void PrintInfo(int age) {
        System.out.println(age);
    }

    public void PrintInfo(String name, int age) {
        System.out.println(name + " " + age);
    }
}

public class Polymorphism {
    public static void main(String args[]) {
        Student s1 = new Student();
        s1.name = "Jess";
        s1.age = 19;

        s1.PrintInfo(s1.age);
        s1.PrintInfo(s1.name);
        s1.PrintInfo(s1.name, s1.age);
    }
}
