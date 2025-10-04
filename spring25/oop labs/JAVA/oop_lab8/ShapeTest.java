public class ShapeTest {
    public static void main(String[] args) {
        // array of shapes
        Shape[] shapes = new Shape[3];
        // initialising different objects
        shapes[0] = new Circle(5);
        shapes[1] = new Square(5);
        shapes[2] = new Triangle(5, 5);

        // loop to invoke calculatearea method for each shape
        for (Shape shape : shapes) {
            System.out.println("The area of " + shape.getClass().getName() + " is " + shape.calculateArea());
        }
    }
}