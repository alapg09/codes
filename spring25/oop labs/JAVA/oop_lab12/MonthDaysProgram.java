package oop_lab12;

import java.util.Scanner;
// have to import this exception to handle the case when the user enters a non-integer value
import java.util.InputMismatchException;

public class MonthDaysProgram {
    public static void main(String[] args) {
        // defining the arrays for months and days
        String[] months = {"January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November", "December"};
        
        int[] dom = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        Scanner input = new Scanner(System.in);
        
        try {
            // getting inpout inside try now to catch the InputMismatchException
            System.out.print("Enter an integer between 1 and 12: ");
            int monthNumber = input.nextInt();
            
            // arrays are zero-indexed, so we subtract 1 from the user input
            int index = monthNumber - 1;
            
            // displaying the corresponding month and its number of days
            System.out.println(months[index] + " has " + dom[index] + " days");
            
        } catch (InputMismatchException e) {
            // handling the exception if the user enters a non-integer value
            System.out.println("Invalid input! Please enter an integer.");
        } catch (ArrayIndexOutOfBoundsException e) {
            // handling the exception if the user enters a wrong number
            System.out.println("Wrong number! Please enter a number between 1 and 12.");
        } finally {
            // closng the scanner inside finally block
            input.close();
        }
    }
}