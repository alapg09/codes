
// // no specified data fields or methods for this class in the task description
// public class Shape {
// }

// class TwoDimensionalShape extends Shape {
//     public double getArea() {
//         return 0.0; // this is default value, it will be overridden in subclasses according to different formulas for different shapes
//     }
// }

// class ThreeDimensionalShape extends Shape {
//     public double getArea() {
//         return 0.0; // default --> will be overridden in subclasses
//     }

//     public double getVolume() {
//         return 0.0; // default
//     }
// }

// // all the given 2D Shapes
// // Circle
// class Circle extends TwoDimensionalShape {
//     private double radius;  // radius

//     // constructor
//     public Circle(double radius) {
//         this.radius = radius;
//     }

//     @Override
//     public double getArea() {
//         return Math.PI * radius * radius;   // area of a circle using PI value from Math class
//     }

// }

// // Squaer
// class Square extends TwoDimensionalShape {
//     private double side;    // legth of a side  

//     // constructor
//     public Square(double side) {
//         this.side = side;
//     }

//     // area getter
//     @Override
//     public double getArea() {
//         return side * side;
//     }

// }

// // Triangle
// class Triangle extends TwoDimensionalShape {
//     private double base, height;    // base and height of trriangle

//     // constructor
//     public Triangle(double base, double height) {
//         this.base = base;
//         this.height = height;
//     }

//     @Override
//     public double getArea() {
//         return 0.5 * base * height;
//     }

// }

// // all 3D Shapes

// // Sphere
// class Sphere extends ThreeDimensionalShape {
//     private double radius;  // radius

//     // constructor
//     public Sphere(double radius) {
//         this.radius = radius;
//     }

//     // overriden getArea and getVolume method
//     @Override
//     public double getArea() {
//         return 4 * Math.PI * radius * radius;
//     }

//     @Override
//     public double getVolume() {
//         return (4.0 / 3) * Math.PI * Math.pow(radius, 3);
//     }
// }

// class Cube extends ThreeDimensionalShape {
//     private double side;    // side length

//     // constructor
//     public Cube(double side) {
//         this.side = side;
//     }

//     // pverrriden getArea and getVolume method
//     @Override
//     public double getArea() {
//         return 6 * side * side;
//     }

//     @Override
//     public double getVolume() {
//         return Math.pow(side, 3);
//     }
// }

// class Tetrahedron extends ThreeDimensionalShape {
//     private double edge;    // leght of each edge of the tetrahedorn

//     // constructor
//     public Tetrahedron(double edge) {
//         this.edge = edge;
//     }
//     // overriden getArea and getVolume method
//     @Override
//     public double getArea() {
//         return Math.sqrt(3) * edge * edge;
//     }
//     // formula for vol and surface area are found on the internet
//     @Override
//     public double getVolume() {
//         return (Math.pow(edge, 3)) / (6 * Math.sqrt(2));
//     }
// }

