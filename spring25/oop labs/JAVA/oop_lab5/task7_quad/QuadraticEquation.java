package oop_lab5.task7_quad;

public class QuadraticEquation {
    private double a;
    private double b;
    private double c;

    // constructor
    public QuadraticEquation(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    // getters
    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }

    public double getC() {
        return c;
    }

    // discriminant calc
    public double getDiscriminant() {
        return (b * b) - (4 * a * c);
    }

    // fist root if discriminant ≥ 0 otherwise 0
    public double getRoot1() {
        double discriminant = getDiscriminant();
        return (discriminant >= 0) ? (-b + Math.sqrt(discriminant)) / (2 * a) : 0;
    }

    // second root if discriminant ≥ 0 otherwise 0
    public double getRoot2() {
        double discriminant = getDiscriminant();
        return (discriminant >= 0) ? (-b - Math.sqrt(discriminant)) / (2 * a) : 0;
    }
}
