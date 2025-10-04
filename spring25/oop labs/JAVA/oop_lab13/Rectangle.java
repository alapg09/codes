package oop_lab13;

abstract class Shape {
    abstract int getArea();
}

class Rectangle extends Shape {
    protected int width;
    protected int height;

    public void setWidth(int w) { width = w; }
    public void setHeight(int h) { height = h; }

    public int getArea() { return width * height; }
}

class Square extends Shape {
    protected int side;

    public void setSide(int s) { side = s; }

    public int getArea() { return side * side; }
}
