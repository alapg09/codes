import java.util.Scanner;

public class task5{
    public static void main(String[] args) {
        // new scanner object
        Scanner sc = new Scanner(System.in);

        //taking inptus
        System.out.println("Enter the loan amount: ");
        double loan_amount = sc.nextDouble();
        System.out.println("Enter the loan period (number of years): ");
        int loan_period = sc.nextInt();

        //validating inputs
        if(loan_amount < 0 || loan_period < 0){
            System.out.println("Invalid input");
            System.exit(0);
        }


        // variables
        double monthly_payment, total_payment;
       
        // printing and calculating in a tabular format
        System.out.println("Interest Rate\tMonthly Payment\tTotal Payment");
        for(double interest = 5.000; interest <= 10.000; interest+=0.250){
            double monthly_interest = interest / 100 / 12;  // monthly interest rate
            int loan_period_months = loan_period * 12;  

            // usign the formula given
            monthly_payment = (loan_amount * monthly_interest) / (1 - (1 / (Math.pow(1 + monthly_interest, loan_period_months))));
            total_payment = monthly_payment * loan_period * 12;
            
            System.out.printf("%.3f\t\t%.2f\t\t%.2f\n", interest, monthly_payment, total_payment);

        }

        sc.close();

    }



}