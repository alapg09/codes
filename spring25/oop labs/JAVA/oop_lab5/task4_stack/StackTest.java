// user input is not taken because we only have to test
public class StackTest {
    public static void main(String[] args) {
        Stack stack = new Stack(); // Create a stack instance

        // pushing elements for testing
        System.out.println("Pushing elements: 10, 20, 30");
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.display();  

        // Test popping an element
        System.out.println("\nPopping the top element:");
        stack.pop();     // pops 30
        stack.display();  

        // pushing elements to a full stack to check validation
        System.out.println("\nPushing elements to full stack:");
        for(int i = 0; i < 8; i++){
            stack.push(i);
        }
        stack.push(100);

        // popping elements to empty the stack
        System.out.println("\nPopping all elements:");
        for(int i = 0; i < 10; i++){
            stack.pop();
        }
        // popping from an empty stack to check validation
        System.out.println("\nAttempting to pop from empty stack:");
        stack.pop();

    }
}
