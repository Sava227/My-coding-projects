package Class_and_object;

public class Program {
    public static void main(String[] args) {

        Person p1 = new Person();
        p1.name = "Alice";
        p1.age = 30;
        p1.print();

        Person p2 = new Person("Bob", 25);
        p2.print();

        Person p3 = new Person("Charlie");
        p3.print();

        Person p4 = new Person(40);
        p4.print();

        String name = p1.getName();
        System.out.println("Hello " + name);
    }
}

class Person {
    String name;
    int age;

    public Person() {}          //empty constructor
    public Person(String name, int age) {   //age + name
    this.name = name;
    this.age = age;
    }

    public Person(int age) {this.age = age;}        //only age
    public Person(String name) {        //only name
        this.name = name;
    }

    public void print() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }

    public String getName() {
        return name;
    }
}