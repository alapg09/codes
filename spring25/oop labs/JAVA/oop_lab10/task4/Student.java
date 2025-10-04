package oop_lab10.task4;

public class Student {
    private String studentID;
    private String name;
    private int age;
    private String course;

    //getter and setters
    public String getStudentID() {
        return studentID;
    }
    public void setStudentID(String studentID) {
        this.studentID = studentID;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public String getCourse() {
        return course;
    }
    public void setCourse(String course) {
        this.course = course;
    }


    // constructor with all parameters
    public Student(String studentID, String name, int age, String course) {
        this.studentID = studentID;
        this.name = name;
        this.age = age;
        this.course = course;
    }

    // constructor chaining (3 parameterss)
    public Student(String studentID, String name, String course) {
        this(studentID, name, 18, course);  // default age = 18
    }

    // constructor with only name
    public Student(String name) {
        this("000", name, 18, "Undeclared");    // calss the constructor will 3 parameters which inturn calls the one will 4. hence, chaining is obtianed
    }

    // display method
    public void displayInfo() {
        System.out.println("Student ID: " + studentID);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Course: " + course);
        System.out.println("-------------------------");
    }
}

class EnrollmentSystem {
    public static void main(String[] args) {
        // creating objects of Student class with diff paraneters
        Student s1 = new Student("501492", "Ali", "Math");
        Student s2 = new Student("502087", "Zia", 19, "CS");
        Student s3 = new Student("Alap");

        // displaying information of students
        s1.displayInfo();
        s2.displayInfo();
        s3.displayInfo();
    }
}
