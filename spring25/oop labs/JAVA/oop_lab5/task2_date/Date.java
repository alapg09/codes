public class Date{
    private int month;
    private int day; 
    private int year;

    public Date(int month, int day, int year){
        this.month = month;
        this.day = day;
        this.year = year;
    }

    // Getters

    // month getter
    public int getMonth(){
        return month;
    }

    // day getter
    public int getDay(){
        return day;
    }

    // year getter  
    public int getYear(){
        return year;
    }

    // Setters

    // month setter that checks for valid year  
        
    public void setMonth(int month){
        if(month > 0 && month <= 12){
            this.month = month;
        }
    }

    // day setter that checks for valid year  
        
    public void setDay(int day){
        if(day > 0 && day <= 31){
            this.day = day;
        }
    }

    // year setter that checks for valid year  
        
    public void setYear(int year){
        if(year > 0){
            this.year = year;
        }
    }

    public void displayDate(){
        System.out.println(month + "/" + day + "/" + year);
    }

}