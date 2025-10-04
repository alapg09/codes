
public class EmployeeTest {
    public static void main(String[] args) {
        // create two Employee objects
        Employee emp1 = new Employee("Alap", "Gohar", 50000);
        Employee emp2 = new Employee("Abdullah", "Farooq", 60000);

        // calculate yearly salary of each Employee
        double emp1_sal = emp1.getSalary()*12;
        double emp2_sal = emp2.getSalary()*12;

        // display yearly salary of each Employee
        System.out.println(emp1.getFirstName() + " " + emp1.getLastName() + "'s yearly salary: " + emp1_sal);
        System.out.println(emp2.getFirstName() + " " + emp2.getLastName() + "'s yearly salary: " + emp2_sal);
        
        // update Employee salaries
        emp1.setSalary(emp1_sal + emp1_sal * 0.1);
        emp2.setSalary(emp2_sal + emp2_sal * 0.1);
        
        // calculate yearly salary of each Employee
        emp1_sal = emp1.getSalary()*12;
        emp2_sal = emp2.getSalary()*12;

        // display yearly salary of each Employee
        System.out.println(emp1.getFirstName() + " " + emp1.getLastName() + "'s yearly salary: " + emp1_sal);
        System.out.println(emp2.getFirstName() + " " + emp2.getLastName() + "'s yearly salary: " + emp2_sal);

    }
}
