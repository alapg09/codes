public class DateTest{
    public static void main(String[] args){
        // Create a Date object
        Date date = new Date(1, 1, 2021);

        // Display the date
        date.displayDate();
        
        // check if the input valildation works or not
        date.setMonth(13);
        date.setDay(32);
        date.setYear(-1);
        date.displayDate();

        // Setting new valid date
        date.setMonth(12);
        date.setDay(31); 
        date.setYear(2021);
        // displaying new
        date.displayDate();

    }
}
