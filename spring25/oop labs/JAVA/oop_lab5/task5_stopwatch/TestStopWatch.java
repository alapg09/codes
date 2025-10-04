import java.util.Random;

public class TestStopWatch {
    public static void main(String[] args) {
        int[] numbers = new int[100000];
        Random random = new Random();

        // Populate the array with random integers
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = random.nextInt(100000);
        }

        StopWatch stopwatch = new StopWatch(); // Start timing
        stopwatch.start();

        // Perform selection sort
        selectionSort(numbers);

        stopwatch.stop(); // Stop timing

        System.out.println("Time taken to sort 100,000 numbers using selection sort: " 
                           + stopwatch.getElapsedTime() + " milliseconds");
    }

    // sllection sort method
    public static void selectionSort(int[] arr) {
        int n = arr.length; // calculate the length of the array

        for (int i = 0; i < n - 1; i++) {       // one by one move boundary of unsorted subarray
            int minIndex = i;

            // finding   the index of the minimum element
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {       // checking if the current element is less than the minimum element
                    minIndex = j;
                }
            }

            // Swap the found minimum element with the first element
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}
