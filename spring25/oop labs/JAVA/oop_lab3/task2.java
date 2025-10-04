import java.util.Scanner;

public class task2{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);

        int[] arr = new int[10];   
        int counter = 0;

        System.out.println("Enter 10 integers into the array: ");
        
        // taking input and checking if the number is greater than 10
        for(int i = 0; i < 10; i++){
            arr[i] = sc.nextInt();
            if(arr[i] >= 10){
                counter++;
            }
            }

        System.out.println("Number of elements greater than 10: " + counter);

        sc.close();
    }
}
// 