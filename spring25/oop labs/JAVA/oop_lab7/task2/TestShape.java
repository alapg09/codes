// public class TestShape {
//     public static void main(String[] args) {
//         // array that is containing all different shapes
//         Shape[] shapes = new Shape[6];
//         shapes[0] = new Circle(5); // creating a circle object with radius 5
//         shapes[1] = new Square(4); // creating a square object with side 4
//         shapes[2] = new Triangle(6, 3); // creating a triangle object with base 6 and height 3  
//         shapes[3] = new Sphere(3); // creating a sphere object with radius 3
//         shapes[4] = new Cube(2); // creating a cube object with side 2
//         shapes[5] = new Tetrahedron(4); // creating a tetrahedron object with side 4

//         System.out.println("----------------------"); // f0r beautification purposes

//         // loop to iterate to print descriptions
//         for (int i = 0; i < shapes.length; i++) { 
//             // this line is printing the class name of the shape // simple name returns only the class name and not the package
//             System.out.println("shapes[" + i + "] is a " + shapes[i].getClass().getSimpleName());

//             if (shapes[i] instanceof TwoDimensionalShape) { // using instanceof to check if the shape is 2D or 3D
//                 System.out.println("Area: " + ((TwoDimensionalShape) shapes[i]).getArea()); // since there is no getArea method in Shape class, we need to cast it to TwoDimensionalShape first to get the overriden area 
//             } 
//             else if (shapes[i]instanceof ThreeDimensionalShape) {
//                 System.out.println("Surface Area: " + ((ThreeDimensionalShape) shapes[i]).getArea());
//                 System.out.println("Volume: " + ((ThreeDimensionalShape) shapes[i]).getVolume());   // again, we typecast the superclass shape to 3dshape 
//             }

//             System.out.println("-----------------------"); 
//         }
//     }
// }
