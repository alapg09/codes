import java.util.Scanner;   // for taking input from the user

public class task3{
    public static void main(String[] args){
        // create a scanner object
        Scanner sc = new Scanner(System.in);

        // declaring the variables
        double tuition, increment;
        int years;

        // taking input from the user
        System.out.println("Enter the current tuition(in $): ");
        tuition = sc.nextDouble();

        System.out.println("Enter the percentage increment(in %): ");
        increment = sc.nextDouble();

        System.out.println("Enter the number of years: ");
        years = sc.nextInt();

        // checking if the input is valid
        if(years < 0 || tuition < 0 || increment < 0){
            System.out.println("Invalid input");
            System.exit(0);
        }

        // calculating new tuition after the given years using the formula for exponential growth
        double new_tuition = tuition*Math.pow(1+increment/100, years);
        // printing the answer
        System.out.println("The tuition after " + years + " years will be: " + new_tuition);

        // calculating the total cost of four years after the given years
        Double four_year_tuition = 0.0, per_year = new_tuition;
        
        // summing up the new fee for every year
        for(int i = 0; i < 4; i++){
            four_year_tuition += per_year;
            per_year *= (1+increment/100);
        }

        // printing the answer
        System.out.println("The total cost of four years after " + years + " is: " + four_year_tuition);
        sc.close();
    }
}