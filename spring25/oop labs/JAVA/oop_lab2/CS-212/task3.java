// // Zeller's Congruence

// import java.util.Scanner;

// public class task3{
//     public static void main(String[] args){
//         Scanner input = new Scanner(System.in);
//         System.out.print("Enter the year: (e.g., 2012): ");
//         int year = input.nextInt();
//         System.out.print("Enter the month: 1-12: ");
//         int m = input.nextInt();
//         System.out.print("Enter the day of the month: 1-31: ");
//         int q = input.nextInt();
        
//         if (m == 1 ){
//             m = 13;
//             year--;
//         }
//         else if (m == 2 ){
//             m = 14;
//             year--;
//         }

//         int j = year/100;
//         int k = year % 100;
//         int h;
//         h = (q + (26 * (m + 1) / 10) + k + (k / 4) + (j / 4) + 5 * j) % 7;


//         String day_of_week = "";
//         switch(h){
//             case 0: day_of_week = "Saturday"; break;
//             case 1: day_of_week = "Sunday"; break;
//             case 2: day_of_week = "Monday"; break;
//             case 3: day_of_week = "Tuesday"; break;
//             case 4: day_of_week = "Wednesday"; break;
//             case 5: day_of_week = "Thursday"; break;
//             case 6: day_of_week = "Friday"; break;

//         }
//         input.close();


//         System.out.println("Day of the week is " + day_of_week);
//     }
// }