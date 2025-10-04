package oop_lab10.task3;

public class Employee {
    private String name;
    private double salary;
    private String jobTitle;

    // constructor
    public Employee(String name, double salary, String jobTitle) {
        this.name = name;
        this.salary = salary;
        this.jobTitle = jobTitle;
    }

    // getters and setters
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public double getSalary() {
        return salary;
    }
    public void setSalary(double salary) {
        this.salary = salary;
    }
    public String getJobTitle() {
        return jobTitle;
    }
    public void setJobTitle(String jobTitle) {
        this.jobTitle = jobTitle;
    }

    // method to be overridden
    public void calculateBonus() {
        double bonus = 0.05 * salary;
        System.out.println(jobTitle + " " + name + " gets a bonus of $" + bonus);
    }
    // for displaying employee info
    @Override
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                ", salary=" + salary +
                ", jobTitle='" + jobTitle + '\'' +
                '}';
    }
}

class Manager extends Employee {

    //constructor
    public Manager(String name, double salary) {
        super(name, salary, "Manager");
    }

    @Override
    public void calculateBonus() {
        double bonus = 0.10 * this.getSalary();
        System.out.println(this.getJobTitle() + " " + this.getName() + " gets a bonus of $" + bonus);
    }
}


class Engineer extends Employee {

    //constructpr
    public Engineer(String name, double salary) {
        super(name, salary, "Engineer");
    }

    @Override
    public void calculateBonus() {
        double bonus = 0.08 * this.getSalary();
        System.out.println(this.getJobTitle() + " " + this.getName() + " gets a bonus of $" + bonus);
    }
}


class EmployeeDemo {
    public static void main(String[] args) {
        Employee emp1 = new Manager("Ahsan", 100000);
        Employee emp2 = new Engineer("Fatima", 85000);
        Employee emp3 = new Employee("Zara", 60000, "Clerk");

        // Polymorphic method calls
        emp1.calculateBonus();
        emp2.calculateBonus();
        emp3.calculateBonus();
    }
}
