// import java.util.Scanner;

// public class QuadraticEquationTest {
//     public static void main(String[] args) {
//         Scanner input = new Scanner(System.in);

//         // prompt user for coefficients 
//         System.out.print("Enter coefficient a: ");
//         double a = input.nextDouble();

//         System.out.print("Enter coefficient b: ");
//         double b = input.nextDouble();

//         System.out.print("Enter coefficient c: ");
//         double c = input.nextDouble();

//         // validation -->  a should not be 0 for a quadratic equation
//         if (a == 0) {
//             System.out.println("Coefficient 'a' cannot be 0. Not a quadratic equation.");
//             input.close();
//             return;
//         }

//         // create QuadraticEquation object
//         QuadraticEquation equation = new QuadraticEquation(a, b, c);

//         // displying the determinant
//         double discriminant = equation.getDiscriminant();
//         System.out.println("\nDiscriminant: " + discriminant);

//         // display results based on discriminant
//         if (discriminant > 0) {
//             System.out.println("The equation has two roots: " +
//                                equation.getRoot1() + " and " + equation.getRoot2());
//         } else if (discriminant == 0) {
//             System.out.println("The equation has one root: " + equation.getRoot1());
//         } else {
//             System.out.println("The equation has no real roots.");
//         }
//     }
    
// }
