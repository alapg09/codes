import java.util.Scanner;   // importing scanner class

public class task4{
    public static void main(String[] args){
        // creating scanner object
        Scanner sc = new Scanner(System.in);

        // taking input for number of students
        System.out.print("Enter the number of Students: ");
        int n = sc.nextInt();

        // creating arrays to store names and scores
        String[] names = new String[n];
        int[] scores = new int[n];


        // taking inputs in the arrays
        for(int i=0; i<n; i++){
            System.out.print("Enter the name of Student " + (i+1) + ": ");
            names[i] = sc.next();
            System.out.print("Enter the score of Student " + (i+1) + ": ");
            scores[i] = sc.nextInt();

            // checking for valid input --> decrements i to make sure that the same student is asked again
            if(scores[i] < 0 || scores[i] > 100){
                System.out.println("Invalid score. Please entre a score between 0 and 100.");
                i--;
            }
        }


        // linear search to find the highest score
        int max = scores[0], index = 0;
        for(int i = 0; i < n; i++){
            if(scores[i] > max){
                max = scores[i];
                index = i;
            }
        }


        // displaying the highest score and the students who got it
        System.out.println("The highst score is: " + max + " and the students who got this score are: " + names[index]);
        sc.close();
    }
}