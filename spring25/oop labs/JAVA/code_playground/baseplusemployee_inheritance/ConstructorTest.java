// Fig. 9.17: ConstructorTest.java
// Display order in which superclass and subclass constructors are called.

public class ConstructorTest
{
    public static void main( String args[] )
    {
        CommissionEmployee4 employee1 = new CommissionEmployee4(
            "Bob", "Lewis", "333-33-3333", 5000, .04 );

        System.out.println(employee1);

        BasePlusCommissionEmployee5 employee2 =
            new BasePlusCommissionEmployee5(
            "Lisa", "Jones", "555-55-5555", 2000, .06, 800 );

        System.out.println(employee2);

        BasePlusCommissionEmployee5 employee3 =
            new BasePlusCommissionEmployee5(
            "Mark", "Sands", "888-88-8888", 8000, .15, 2000 );

        System.out.println(employee3);
    } // end main
} // end class ConstructorTest
