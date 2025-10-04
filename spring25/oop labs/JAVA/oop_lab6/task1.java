// ths is the base class
class Animal {
    String name;

    // constructor
    public Animal(String name){
        this.name = name;
    }  
    // speak function
    void speak() {
        System.out.println("An animal makes a sound");
    }
}

// subclass of Animal named Dog
class Dog extends Animal {
    String breed;
    
    // constructor that uses super() to call the constructor of the base class
    public Dog(String name, String breed){
        super(name);
        this.breed = breed;
    }

    // overriding the speak function
    @Override
    void speak() {
        System.out.println("A dog barks");
    }
}

// main class
public class task1 {
    public static void main(String[] args) {
        Dog myDog = new Dog("Buddy", "GoldenRetriever");    // creating an object of Dog class
        
        myDog.speak();  // calling the speak function of Dog class
    }   
}
