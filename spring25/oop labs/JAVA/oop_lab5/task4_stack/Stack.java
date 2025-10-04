public class Stack {
    private int[] stck;  // array to hold stack elements
    private int tos;     // top of stack

    // constructor initializes the stack and sets tos to -1 (empty stack)
    public Stack() {
        stck = new int[10];
        tos = -1;
    }

    // push method
    public void push(int item) {
        if (tos == stck.length - 1) {       // chcking ig the stack is full
            System.out.println("Stack is full. Cannot push " + item);
        } else {
            stck[++tos] = item;
            System.out.println("Pushed: " + item);
        }
    }

    // pop method 
    public void pop() {
        if (tos < 0) {  // checking if the stack is empty
            System.out.println("stck is empty. Cannot pop.");
        } else {;
            System.out.println("Popped: " + stck[tos]);
            tos--; // tos is decremented to point to the next lower element and hence the top element is removed as it is no longer accessable
        }
    }

    // display current stack elements
    public void display() {
        if (tos < 0) {
            System.out.println("Stack is empty.");
        } else {
            System.out.print("Stack elements (top to bottom): ");   // im printing top to bottom because it is a stacck
            for (int i = tos; i >= 0; i--) {
                System.out.print(stck[i] + " ");
            }
            System.out.println();
        }
    }
}
