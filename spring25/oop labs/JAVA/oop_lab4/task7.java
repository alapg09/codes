import java.util.Scanner;

public class task7{
    public static void main(String[] args){
        // n ew Scanner object
        Scanner sc = new Scanner(System.in);

        // taking inputs in an array of size 10
        System.out.print("Enter 10 numbers: ");
        double[] arr = new double[10];

        for(int i = 0; i < 10; i++){
            arr[i] = sc.nextDouble();
        }

        // variables declaratoin
        double mean, std_dev, sum = 0.0, squared_sum = 0.0;

        //loop is running to calculate the sum and squared sum for the formula
        for(int i = 0; i < 10; i++){
            sum += arr[i];
            squared_sum += Math.pow(arr[i], 2);
        }
        // calculating mean
        mean = sum/10;
        //formula for standard deviation
        std_dev = Math.sqrt((squared_sum - (sum*sum)/10)/9);
        System.out.println("Mean is " + mean);
        // printing std dev to 5 decimal places using printf and %,5f
        System.out.printf("Standard Deviation is %.5f", std_dev);
        sc.close();
    }
}