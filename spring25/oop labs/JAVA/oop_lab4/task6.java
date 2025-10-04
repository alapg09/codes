
public class task6{
    public static void main(String[] args){
        int count = 0;  //for counting the number of all combination

        //outer loop will runs from 1-7 and for each element of outer loop, the inner loop will run from the next number to 7
        //giving all the possible combination of 2 numbers from 1-7
        for(int i = 1; i <=     7; i++){
            for(int j = i+1; j <= 7; j++){
                System.out.println(i + " " + j);    //displaying
                count++;    // increment for keeping track
            }
        }

        // displaying
        System.out.println("Total nmber of all combination: " + count);
        
    }
}