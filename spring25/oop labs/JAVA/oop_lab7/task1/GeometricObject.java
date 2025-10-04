import java.util.Date;  // for date created

public class GeometricObject{
    // private data fields with default values
    private String color = "white"; 
    private boolean filled = false;
    private Date dateCreated;

    // no-arg constructor
    public GeometricObject(){
        dateCreated = new Date();
    }

    // parameterized constructor
    public GeometricObject(String color, boolean filled){
        dateCreated = new Date();
        this.color = color;
        this.filled = filled;
    }

    // color getter and setter
    public String getColor(){
        return this.color;
    }
    public void setColor(String color){
        this.color = color;
    }

    // getter and settr for isFilled
    public boolean isFilled(){
        return filled;
    }
    public void setFilled(boolean filled){
        this.filled = filled;
    }

    // date created getter
    public Date getDateCreated(){
        return dateCreated;
    }

    // returns an overriden string representation of this objects
    @Override
    public String toString(){
        return "GeometricObject created on " + dateCreated + "\ncolor: " + color + " and filled: " + filled;
    }
}

class Rectangle extends GeometricObject{
    // private data fields with defualt valies
    private double width = 1.0;
    private double height = 1.0;

    // constructors
    public Rectangle(){
        super();
    }
    public Rectangle(double width, double height){
        super();
        this.width = width;
        this.height = height;
    }
    // ****i did not add getters and setters fro widht and height because they were not required in the task descripyion*****

    // area and perimeter getters
    public double getArea(){
        return width * height;
    }
    public double getPerimeter(){
        return 2 * (width + height);
    }


    // overriden tostring
    @Override
    public String toString(){
        return "Rectangle: width: " + width + " height: " + height;
    }

}
