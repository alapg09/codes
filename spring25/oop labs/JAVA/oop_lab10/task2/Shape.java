    package oop_lab10.task2;

    public abstract class Shape {
        protected abstract void calculateArea(); // Polymorphic method
    }

    class Circle extends Shape {
        // circle has a radius
        private double radius;

        // constructor
        public Circle(double radius) {
            this.radius = radius;
        }

        // getter and setter
        public double getRadius() {
            return radius;
        }
        public void setRadius(double radius) {
            this.radius = radius;
        }

        // overrriding the calculateArea method
        @Override
        public void calculateArea() {
            double area = Math.PI * radius * radius;
            System.out.println("Area of Circle: " + area);
        }
    }

    class Square extends Shape {
        // square has a side
        private double side;

        //getters adn setter
        public double getSide() {
            return side;
        }
        public void setSide(double side) {
            this.side = side;
        }

        // constructor
        public Square(double side) {
            this.side = side;
        }

        @Override
        public void calculateArea() {
            double area = side * side;
            System.out.println("Area of Square: " + area);
        }
    }

    class Triangle extends Shape {
        // triangle has a base and height
        private double base;
        private double height;

        // getters and setters
        public double getBase() {
            return base;
        }
        public void setBase(double base) {
            this.base = base;
        }
        public double getHeight() {
            return height;
        }
        public void setHeight(double height) {
            this.height = height;
        }

        // constructor
        public Triangle(double base, double height) {
            this.base = base;
            this.height = height;
        }

        @Override
        public void calculateArea() {
            double area = 0.5 * base * height;
            System.out.println("Area of Triangle: " + area);
        }
    }


    class ShapeDemo {
        public static void main(String[] args) {
            // different objects of different shapes having reference of Shape class
            Shape s1 = new Circle(5);
            Shape s2 = new Square(4);
            Shape s3 = new Triangle(6, 3);

            // polymorphism is here
            s1.calculateArea();
            s2.calculateArea();
            s3.calculateArea();
        }
    }



