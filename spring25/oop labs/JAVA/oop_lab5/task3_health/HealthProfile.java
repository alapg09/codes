import java.time.LocalDate; // for age calculations

public class HealthProfile{
    private String firstName;
    private String lastName;
    private String gender;
    // date of birth with three different attributes for day, year and month
    private int day;
    private int month;
    private int year;

    private double height;
    private double weight;


    // constructor with validation for invalid date
    public HealthProfile(String firstName, String lastName, String gender, int day, int month, int year, double height, double weight){
        this.firstName = firstName;
        this.lastName = lastName;
        this.gender = gender;
        if(day>=1 && day<=31){
            this.day = day;
        }
        else{
            this.day = 0;   // shows error
        }
        if(month >=1 && month <= 12){
            this.month = month;
        }
        else{
            this.month = 0; // error
        }
        if(year > 0){
            this.year = year;
        }
        else{
            this.year = 0; 
        }

        this.height = height;
        this.weight = weight;
    }

    // Setters

    // firstName setter
    public void setFirstName(String firstName){
        this.firstName = firstName;
    }

    // lastName setter
    public void setLastName(String lastName){
        this.lastName = lastName;
    }

    // gender setter
    public void setGender(String gender){
        this.gender = gender;
    }

    // day setter
    public void setDay(int day){
        if(day > 0 && day <= 31){
            this.day = day;
        }
    }

    // month setter
    public void setMonth(int month){
        if(month > 0 && month <= 12){
            this.month = month;
        }
    }

    // year setter
    public void setYear(int year){
        if(year > 0){
            this.year = year;
        }
    }


    // Getters

    // firstName getter
    public String getFirstName(){
        return firstName;
    }

    // lastName getter
    public String getLastName(){
        return lastName;
    }

    // gender getter
    public String getGender(){
        return gender;
    }

    // day getter
    public int getDay(){
        return day;
    }

    // month getter
    public int getMonth(){
        return month;
    }

    // year getter
    public int getYear(){
        return year;
    }

    public double getHeight() {
        return height;
    }

    public double getWeight() {
        return weight;
    }



    public int calculateAge(){
        return LocalDate.now().getYear() - year;
    }
    // algorithm is used from the book execise
    public double calculateBMI() {
        return (weight * 703) / (height * height);  // BMI formula (imperial units)
    }

    // algorithm is used from the book execise
     public int maximumHeartRate() {
        return 220 - calculateAge();
    }


    // algorithm is used from the book execise
    public String targetHeartRateRange() {
        double lower = maximumHeartRate() * 0.50;
        double upper = maximumHeartRate() * 0.85;
        return String.format("%.0f - %.0f bpm", lower, upper);
    }

    // displaying the results
    public void displayBMIChart() {
        System.out.println("\nBMI VALUES");
        System.out.println("Underweight: less than 18.5");
        System.out.println("Normal:      between 18.5 and 24.9");
        System.out.println("Overweight:  between 25 and 29.9");
        System.out.println("Obese:       30 or greater");
    }
    




}