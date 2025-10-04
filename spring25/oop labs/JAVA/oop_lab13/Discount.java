package oop_lab13;

interface DiscountStrategy {
    double getDiscount(double price);
}

class RegularDiscount implements DiscountStrategy {
    public double getDiscount(double price) {
        return price * 0.1;
    }
}

class PremiumDiscount implements DiscountStrategy {
    public double getDiscount(double price) {
        return price * 0.2;
    }
}

class DiscountCalculator {
    public double calculate(DiscountStrategy strategy, double price) {
        return strategy.getDiscount(price);
    }
}
