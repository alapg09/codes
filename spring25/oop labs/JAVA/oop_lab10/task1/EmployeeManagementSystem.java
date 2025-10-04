package oop_lab10.task1;

// main class
class Employee {
    // required fields -- no access modifier(default) because the lab required direct accessing and modifying of the fields
    String name;
    int id;
    String position;
    double salary;

    // constructor
    public Employee(String name, int id, String position, double salary) {
        this.name = name;
        this.id = id;
        this.position = position;
        this.salary = salary;
    }

    // Method to display employee information
    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.println("Position: " + position);
        System.out.println("Salary: $" + salary);
        System.out.println("--------------------------\n");
    }
}

public class EmployeeManagementSystem {
    public static void main(String[] args) {
        // creating employee objects
        Employee emp1 = new Employee("Ali", 101, "Developer", 80000);
        Employee emp2 = new Employee("Ayesha", 102, "Designer", 75000);
        Employee emp3 = new Employee("Usman", 103, "Tester", 70000);

        // displaying employee information
        emp1.displayInfo();
        emp2.displayInfo();
        emp3.displayInfo();

        // updating details of emp1 directly to demonstrate direct access
        emp1.position = "Senior Developer";
        emp1.salary = 90000;

        // printing new details of emp1
        System.out.println("After updating emp1:");
        emp1.displayInfo();
    }
}
