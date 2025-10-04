import java.util.Scanner;
import java.util.Random;

public class task3{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        // taking the size of the array
        System.out.println("Enter the size of the array: ");
        int size = sc.nextInt();
        if(size < 2){
            System.out.println("Size should be greater than 1!");
            System.exit(0);
        }

        int[] array = new int[size];
        // initializing the populate method 
        populateArray(array, size);

        System.out.println("Array: ");
        printArray(array, size);

        // checking the sorting method
        sortArray(array, size);
        System.out.println("\nSorted array: ");
        printArray(array, size);


        // checking the find method
        System.out.println("\nEnter the element to search: ");
        int number = sc.nextInt();
        int found = findElement(array, number);
        if(found == -1){
            System.out.println("Element not found!");
        }
        else{
            found += 1;
            System.out.println("Element found at position: " + found);
        }
        
        sc.close();
    }
   // initializing an array of size N with random values.
    static void populateArray(int[] array, int N){
        Random rand = new Random(); // random number generator
        for(int i = 0; i < N; i++){
            array[i] = rand.nextInt(100);   // random values between 0 and 100
        }
    }
    // printing the array
    static void printArray(int[] array, int N){
        for(int num: array){
            System.out.print(num + " ");
        }
    }

    // bubble sort algorithm
    static void sortArray(int[] array, int N){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N - i - 1; j++){
                if(array[j] > array[j + 1]){
                    int temp = array[j];    // swapping
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
    // linear search algorithm
    static int findElement(int[] array, int x){
        for(int i = 0; i < x; i++){    // enhanced for statement 
            if(array[i] == x){
                return i;
            }
        }
        return -1;
    }

}