// public class Person{
//     // protected access modifier is used to make the fields accessible in the subclasses
//     protected String name;
//     protected String address;
//     protected String phone;
//     protected String email;

//     // constructor
//     public Person(String name, String address, String phone, String email) {
//         this.name = name;
//         this.address = address;
//         this.phone = phone;
//         this.email = email;
//     }


//     // overrriding teh toString method
//     // i printef only class name and person name in all tostring methods becausethe question asks to print the class and name only
//     @Override
//     public String toString() {
//         return "Class: Person, Name: " + name;
//     }
// }

// // student subclass
// class Student extends Person {

//     private final String status;


//     // constructor
//     public Student(String name, String address, String phone, String email, String status) {
//         super(name, address, phone, email); // callling the constructor of superclass
//         this.status = status;
//     }

//     /// overridden tostring method
//     @Override   
//     public String toString() {
//         return "Class: Student, Name: " + name;
//     }
// }


// class Employee extends Person {
//     // instance variables
//     protected String office;
//     protected double salary;
//     protected Date hireDate;  // custom created date class

//     //constrictor
//     public Employee(String name, String address, String phone, String email, String office, double salary, Date hireDate) {
//         super(name, address, phone, email); // constructor of person class
//         this.office = office;
//         this.salary = salary;
//         this.hireDate = hireDate;
//     }

//     // tostring method --> overriden
//     @Override
//     public String toString() {
//         return "Class: Employee, Name: " + name;
//     }
// }

// // subclass of employee class
// class Faculty extends Employee {
//     private String officeHours;
//     private String rank;

//     public Faculty(String name, String address, String phone, String email, String office, double salary, Date hireDate, String officeHours, String rank) {
//         super(name, address, phone, email, office, salary, hireDate);   // constructor of empliyee class
//         this.officeHours = officeHours;
//         this.rank = rank;
//     }
//     // tostring method
//     @Override
//     public String toString() {
//         return "Class: Faculty, Name: " + name;
//     }
// }


// class Staff extends Employee {
//     private String title;

//     // constructor of staff
//     public Staff(String name, String address, String phone, String email, String office, double salary, Date hireDate, String title) {
//         super(name, address, phone, email, office, salary, hireDate);
//         this.title = title;
//     }

//     @Override
//     public String toString() {
//         return "Class: Staff, Name: " + name;
//     }
// }
// // date class
// class Date {
//     private int year;
//     private int month;
//     private int day;

//     // constructor
//     public Date(int year, int month, int day) {
//         this.year = year;
//         this.month = month;
//         this.day = day;
//     }   


//     // overriden tostring method
//     @Override
//     public String toString() {
//         return day + "/" + month + "/" + year;
//     }
// }