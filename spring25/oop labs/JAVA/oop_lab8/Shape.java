class Shape {
    public double calculateArea(){
        // default value because i havenot impplemented abstraction
        return 0.0;
    }
}

class Circle extends Shape {
    // radius for the circle
    private double radius;

    public Circle(double radius) {
        // constructor
        this.radius = radius;
    }

    // overriding superclass method for area cakculation
    public double calculateArea() {
        return Math.PI * radius * radius;
    }

    // overloaded method for parameterized calculation of area
    public double calculateArea(double new_r) {
        return Math.PI * new_r * new_r;
    }
}

class Square extends Shape {
    // lenght of each side of square
    private double side;

    // Constructor
    public Square(double side) {
        this.side = side;
    }

    //  calculateArea for Square
    public double calculateArea() {
        return side * side;
    }

    // overloading area with a parameter
    public double calculateArea(double new_s) {
        return new_s * new_s;
    }
}

class Triangle extends Shape {
    // base and height of the triangle
    private double base;
    private double height;

    // Constructor
    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    //  calculateArea for Triangle
    public double calculateArea() {
        return 0.5 * base * height;
    }

    // overloading for additional parameters
    public double calculateArea(double new_b, double new_h) {
        return 0.5 * new_b * new_h;
    }
}


