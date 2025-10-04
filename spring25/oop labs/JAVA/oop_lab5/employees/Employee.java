
public class Employee {
    // private instance variables
    private String first_name;
    private String last_name;
    private double salary;

    // constructor that sets the three instance variables
    public Employee(String firstName, String lastName, double sal){
        this.first_name = firstName;
        this.last_name = lastName;
        this.salary = sal;
    }

    // salary getter
    public double getSalary(){
        return salary;
    }   
    // salary setter
    public void setSalary(double sal){
        if(sal>=0){
            this.salary = sal;
        }
    }
    // first name setter
    public void setFirstName(String firstName){
        this.first_name = firstName;
    }
    // last name setter
    public void setLastName(String lastName){
        this.last_name = lastName;
    }
    // first name getter
    public String getFirstName(){
        return first_name;
    }
    // last name getter
    public String getLastName(){
        return last_name;
    }

}
