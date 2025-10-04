import java.util.ArrayList; // for storing animals

// required base class
class Animal {
    // common attributes
    String name;
    int age;

    // Constructor
    Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // no argument constructor
    Animal() {
        this.name = "Unknown";
        this.age = 0;
    }

    // getters and setters
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }

    // required metghods that subclasses must implement
    void makeSound() {
        System.out.println("Some generic animal sound");
    }
    

    // this displays  basic info andd will not be overridden
    void displayInfo() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

// required interface
interface Adoptable {
    void adoptionDetails();
}


// dog subclass extends animal class adn implements the interface
class Dog extends Animal implements Adoptable {

    // constructor
    Dog(String name, int age) {
        super(name, age);

    }

    // no argument constructor
    Dog() {
        super();
    }

    // overriding the makeSound method for dogs
    // dogs bark
    @Override
    void makeSound() {
        System.out.println("Woof! Woof!");
    }
    
    // overriding the method from the interface
    // this method will be used to display the adoption details
    @Override
    public void adoptionDetails() {
        System.out.println(name + " the Dog is ready for adoption. Needs a backyard and daily walks.");
    }
}

// cat subclass extends animal class and implements the interface
class Cat extends Animal implements Adoptable {

    // constructor
    Cat(String name, int age) {
        super(name, age);
    }

    // no argument constructor
    Cat() {
        super();
    }

    // cat meows
    @Override
    void makeSound() {
        System.out.println("Meow! Meow!");
    }

    // cat specific implementation of the interface method
    @Override
    public void adoptionDetails() {
        System.out.println(name + " the Cat is ready for adoption. Prefers a quiet environment.");
    }
}

// main class to test the implementation
public class AnimalShelter {
    public static void main(String[] args) {
        // arraylists with base class and interface reference
        ArrayList<Animal> animals = new ArrayList<>();
        ArrayList<Adoptable> adoptables = new ArrayList<>();

        // populating the arraylists with dog and cat objects
        animals.add(new Dog("Bunty", 3));
        animals.add(new Cat("Catty", 2));

        // adding the objects to the adoptables list
        adoptables.add(new Dog("Woofy", 4));
        adoptables.add(new Cat("Kitty", 1));


        for (Animal a : animals) {
            a.displayInfo();           // Base class method
            a.makeSound();             // Overridden method
            System.out.println();
        }

        for (Adoptable a : adoptables) {

            a.adoptionDetails(); // Interface method
            System.out.println();
        }
    }
}
