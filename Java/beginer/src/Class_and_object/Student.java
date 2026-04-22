package Class_and_object;

public class Student {
    String name;
    static String SchoolName;

    public Student(String name) {
        this.name = name;
    }
}

class main {
    public static void main() {
    Student.SchoolName = "Itgenio";

    Student s1 = new Student("Alice");
    Student s2 = new Student("Bob");

    System.out.println("Name: " + s1.name + ", School: " + Student.SchoolName);
    System.out.println("Name: " + s2.name + ", School: " + Student.SchoolName);
    }
}
