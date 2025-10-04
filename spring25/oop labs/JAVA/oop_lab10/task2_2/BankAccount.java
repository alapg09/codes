package oop_lab10.task2_2;

public class BankAccount {
    // attributes
    private String accountNumber;
    private double balance;
    private String accountHolder;

    // constructor
    public BankAccount(String accountNumber, double balance, String accountHolder) {
        this.accountNumber = accountNumber;
        setBalance(balance);  // Using setter to apply constraints
        this.accountHolder = accountHolder;
    }

    // getters and setters
    public String getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    public String getAccountHolder() {
        return accountHolder;
    }

    
    public void setAccountNumber(String accountNumber) {
        this.accountNumber = accountNumber;
    }

    public void setBalance(double balance) {
        if (balance >= 0)
            this.balance = balance;
        else
            System.out.println("Balance cannot be negative!");
    }

    public void setAccountHolder(String accountHolder) {
        this.accountHolder = accountHolder;
    }

    // Display method
    @Override
    public String toString() {
        return "Account Number: " + accountNumber
        + "\nAccount Holder: " + accountHolder
        + "\nBalance: $" + balance
        + "\n-------------------------";
    }
}


class BankSystem {
    public static void main(String[] args) {
        // creating bank account objects
        BankAccount acc1 = new BankAccount("001", 15000, "Ali Raza");
        BankAccount acc2 = new BankAccount("002", 20000, "Sara Khan");

        // displaying account info
        System.out.println("Account Information:");
        System.out.println(acc1);
        System.out.println(acc2);


        // updating balance with valid value
        acc1.setBalance(18000);
        // Trying to set negative balance (should give a warning)
        acc2.setBalance(-500);

        // Display updated info
        System.out.println("Updated Account Information:");
        System.out.println(acc1);
        System.out.println(acc2);
    }
}

