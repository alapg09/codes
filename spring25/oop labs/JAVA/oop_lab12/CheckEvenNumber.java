package oop_lab12;

public class CheckEvenNumber {
    
    // custom exception for odd numbers
    public static class OddNumberException extends Exception {
        // constructor for the exception
        public OddNumberException(String message) {
            super(message);
        }
        // no-arg constructor
        public OddNumberException() {
            super("Odd number exception occurred!");
        }
    }
    
    // method to check if a number is even
    public static void checkEven(int number) throws OddNumberException {
        if (number % 2 != 0) {
            // new instance of the custom exception is created and thrown
            throw new OddNumberException("Error: " + number + " is an odd number!");
        }
        System.out.println(number + " is an even number.");
    }
    
    public static void main(String[] args) {
        // i have created an array of integers to test the checkEven method
        int[] testNumbers = {2, 7, 10, 15, 22, 33};
        
        // iterating through the array to test each number
        for (int num : testNumbers) {
            try {
                System.out.println("Checking if " + num + " is even:");
                checkEven(num);
            } catch (OddNumberException e) {    // catching the custom exception
                // printing the message from the exception
                System.out.println(e.getMessage());
            }
            System.out.println(); // formatting purposes
        }
    }
}