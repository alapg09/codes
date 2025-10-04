import java.util.Scanner;   // for taking input from the user

public class task2{
    public static void main(String[] args){
        
        // creating an object of Scanner class
        Scanner sc = new Scanner(System.in);
        // declaring variables
        double s, So, Vo, a, t;

        // taking input for initial position, initial velocity, acceleration and time
        System.out.print("Enter initial position: ");
        So = sc.nextDouble();
        System.out.print("Enter initial velocity: ");
        Vo = sc.nextDouble();
        System.out.print("Enter acceleration: ");
        a = sc.nextDouble();
        System.out.print("Enter time: ");
        t = sc.nextDouble();

        // only time and distance are checked because acceleration and initial velocity can be negative
        if(t < 0 || So < 0){
            System.out.println(" cannot be negative");
            System.exit(0);
        }

        // calculating final position
        s = So + Vo*t + 0.5*a*t*t;

        // displaying the final position
        System.out.println("The final position is: " + s);
        sc.close();
        
    }
}