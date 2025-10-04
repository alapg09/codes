class Base
{
	// private void show() 
	// {
	// 	System.out.println("Base::show() called");
	// }
}
public class Derived extends Base
{
	private void show() 
	{
		System.out.println("Derived::show() called");
	}
	public static void main(String[] args) 
	{
		Derived b = new Derived();
		b.show();
	}
}

	