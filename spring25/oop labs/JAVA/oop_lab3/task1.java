// import java.util.Scanner;

// public class task1{
//     public static void main(String[] args){
//         Scanner sc = new Scanner(System.in);
//         System.out.println("Enter the size of array: ");
//         int size = sc.nextInt();

//         if (size < 2){
//             System.out.println("Array size should be greater than 1");
//             System.exit(0);
//         }

//         int[] arr = new int[size];
//         System.out.println("Enter the elements of array: ");

//         for(int i = 0; i < size; i++){
//             arr[i] = sc.nextInt();
//         }

//         int temp = arr[0];
//         arr[0] = arr[size-1];
//         arr[size-1] = temp;

//         System.out.println("After swapping: ");
//         for(int i = 0; i < size; i++){
//             System.out.println(arr[i]);
//         }
//         sc.close();
// }
// }