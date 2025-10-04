// import java.util.Scanner;

// public class TestRectangle {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);

//         // Get user input
//         System.out.print("Enter width: ");
//         double width = sc.nextDouble();

//         System.out.print("Enter height: ");
//         double height = sc.nextDouble();


//         sc.nextLine(); // consuming the newline character
//         System.out.print("Enter color: ");
//         String color = sc.nextLine();

//         System.out.print("Is the rectangle filled (true/false)? ");
//         boolean filled = sc.nextBoolean();

//         // inpur validation
//         if(height <= 0 || width <= 0){
//             System.out.println("Invalid input. Width and height must be greater than 0.");
//             System.exit(1);

//         }


//         // creating the object
//         Rectangle rectangle = new Rectangle(width, height);
//         // setters used because rectangle constructor doesnt take them as parameters as specified in the task
//         rectangle.setColor(color);
//         rectangle.setFilled(filled);

//         // Display properties
//         System.out.println("\nRectangle Details:");
//         System.out.println("Area: " + rectangle.getArea());
//         System.out.println("Rectangle: " + rectangle.getPerimeter());
//         System.out.println("Color: " + rectangle.getColor());
//         System.out.println("Filled or Not: " + rectangle.isFilled());
//     }
// }
