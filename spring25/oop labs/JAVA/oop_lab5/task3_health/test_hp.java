import java.util.Scanner;

public class test_hp{
    public static void main(String[] args){
        // creating scannerr object
        Scanner input = new Scanner(System.in);
        
        // taking inputs for all the attributes
        System.out.println("Enter first name: ");
        String firstName = input.nextLine();

        System.out.println("Enter last name: ");
        String lastName = input.nextLine();

        System.out.println("Enter gender: ");
        String gender = input.nextLine();

        System.out.println("Enter day of birth: ");
        int day = input.nextInt();

        System.out.println("Enter month of birth: ");
        int month = input.nextInt();

        System.out.println("Enter year of birth: ");
        int year = input.nextInt();

        System.out.println("Enter height in inches: ");
        double height = input.nextDouble();

        System.out.println("Enter weight in pounds: ");
        double weight = input.nextDouble();

        // creating object of HealthProfile class
        HealthProfile profile = new HealthProfile(firstName, lastName, gender, day, month, year, height, weight);

        // displaying the health profile summary
        System.out.println("\n--- Health Profile Summary ---");
        System.out.println("Name: " + profile.getFirstName() + " " + profile.getLastName());
        System.out.println("Gender: " + profile.getGender());
        System.out.println("Date of Birth: " + profile.getDay() + "/" + profile.getMonth() + "/" + profile.getYear());
        System.out.println("Age: " + profile.calculateAge() + " years");
        System.out.println("Height: " + profile.getHeight() + " inches");
        System.out.println("Weight: " + profile.getWeight() + " pounds");
        System.out.printf("BMI: %.2f\n", profile.calculateBMI());
        System.out.println("Maximum Heart Rate: " + profile.maximumHeartRate() + " bpm");
        System.out.println("Target Heart Rate Range: " + profile.targetHeartRateRange());
        

        // display BMI Chart
        profile.displayBMIChart();
        input.close();
        }
}