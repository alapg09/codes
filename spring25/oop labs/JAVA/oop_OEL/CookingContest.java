import java.util.ArrayList;
import java.util.Date;

// interface for objects that can be rated
interface Ratable {
    void rate(double rating);
    double getRating();
}

// Abstract Chef class that both junior and senior chefs will extend
abstract class Chef implements Ratable {
    protected String id;
    protected ArrayList<Recipe> recipes;
    protected double rating;
    protected int maxRecipes; // maximum number of recipes allowed
    
    public Chef(String id, int maxRecipes) {
        this.id = id;
        // initialising list of recipes and ratings as default value when new chef is added
        this.recipes = new ArrayList<>();
        this.rating = 0.0;
        this.maxRecipes = maxRecipes; // setting max recipes for the chef
    }
    
    // getters and setters
    public String getId() { return id; }
    public ArrayList<Recipe> getRecipes() {
        return new ArrayList<>(recipes); // returning a copy to protect encapsulation
    }
    // protected because only subclasses should modify the recipes list
    protected void setRecipes(ArrayList<Recipe> recipes) {
        // senior chef is allowed 3 recipes only
        if (recipes.size() > maxRecipes) {
            System.out.println("Senior chefs can only have " + maxRecipes + " recipes.");
        }
        else {
            this.recipes = recipes;
        }
    }
    
    // overriding the methods from Ratable interface
    @Override
    public double getRating() {
        return rating;
    }
    @Override
    public abstract void rate(double rating); // To be implemented by subclasses

    //abstract methods to be implemented by subclasses
    public abstract void  addRecipe(Recipe recipe);
    public abstract void removeRecipe(Recipe recipe);

    // equals method to compare chefs based on their ID
    @Override
    public boolean equals(Object obj) {
        // if same reference, return true
        if (this == obj) return true;
        // if null obj or diff class, return false
        if (obj == null || getClass() != obj.getClass()) return false;
        // downcast to Chef and compare IDs
        Chef chef = (Chef) obj;
        return this.id.equals(chef.id);
    }
    // overriden toString method 
    @Override
    public String toString() {
        return "Chef [id=" + id + ", rating=" + rating + ", recipes=" + recipes.size() + "]";
    }
}

// Senior Chef class
class SeniorChef extends Chef {
    private int yearsOfExperience;
    
    public SeniorChef(String id, int yearsOfExperience) {
        super(id, 3);
        this.yearsOfExperience = yearsOfExperience;
    }
    
    // getter ans setter
    public int getYearsOfExperience() { return yearsOfExperience; }
    public void setYearsOfExperience(int years) { this.yearsOfExperience = years; }
    

    // overriden addRecipe method to add recipe to the list of recipes
    @Override
    public void addRecipe(Recipe recipe) {
        if (getRecipes().size() < 3) {
            this.recipes.add(recipe);
        }
        else{
            System.out.println("LIMIT REACHED! Senior chefs can only have 3 recipes.");
        }
    }
    // overriden removeRecipe method to remove recipe from the list of recipes
    @Override
    public void removeRecipe(Recipe recipe) {
        if (this.recipes.contains(recipe)) {
            this.recipes.remove(recipe);
            System.out.println("Recipe removed: " + recipe.getName());
        } else {
            System.out.println("Recipe not found: " + recipe.getName());
        }
    }
    
    @Override
    public void rate(double rating) {
        // senior chefs are rated differently
        // for example, we might weight their rating based on experience
        double experienceFactor = 1.0 + (yearsOfExperience / 10.0);
        this.rating = (rating * experienceFactor) / 2.0; // scale to keep rating in reasonable range
        
        // ensuring rating stays within 0-10 range
        if (this.rating > 10.0) this.rating = 10.0;
    }
    
    @Override
    public String toString() {
        return "SeniorChef [id=" + getId() + ", experience=" + yearsOfExperience + " years, rating=" + getRating() + "]";
    }
}

// Junior Chef class
class JuniorChef extends Chef {
    private SeniorChef supervisor;
    
    public JuniorChef(String id, SeniorChef supervisor) {
        super(id,1);
        this.supervisor = supervisor;
    }
    
    // getter and setter
    public SeniorChef getSupervisor() { return supervisor; }
    
    public void setSupervisor(SeniorChef supervisor) { this.supervisor = supervisor;}
    
    // overriding the addRecipe method to add recipe to the list of recipes
    @Override
    public void addRecipe(Recipe recipe) {
        // junior chefs can only have 1 recipe
        if (getRecipes().isEmpty()) {
            this.recipes.add(recipe);
        }
        else{
            System.out.println("LIMIT REACHED! Junior chefs can only have 1 recipe.");
        }
    }
    // overriding removerecipe method
    @Override
    public void removeRecipe(Recipe recipe) {
        if (this.recipes.contains(recipe)) {
            this.recipes.remove(recipe);
            System.out.println("Recipe removed: " + recipe.getName());
        } else {
            System.out.println("Recipe not found: " + recipe.getName());
        }
    }
    
    @Override
    public void rate(double rating) {
        // junior chefs might have their rating influenced by their supervisor
        double supervisorInfluence = supervisor.getRating() / 10.0; // Scale to 0-1
        this.rating = (rating * 0.8) + (rating * supervisorInfluence * 0.2);
        
        // ensuring rating stays within 0-10 range
        if (this.rating > 10.0) this.rating = 10.0;
    }
    
    @Override
    public String toString() {
        return "JuniorChef [id=" + getId() + ", supervisor=" + supervisor.getId() + ", rating=" + getRating() + "]";
    }
}

// Recipe class
class Recipe implements Ratable {
    // attributes of the recipe class
    private String id;
    private String name;
    private String ingredients;
    private String instructions;
    private double rating;
    

    // constructor
    public Recipe(String id, String name, String ingredients, String instructions) {
        this.id = id;
        this.name = name;
        this.ingredients = ingredients;
        this.instructions = instructions;
        this.rating = 0.0;
    }
    
    // getters and setters
    public String getId() { return id; }
    public String getName() { return name; }
    public String getIngredients() { return ingredients; }
    public String getInstructions() { return instructions; }
    // setter
    public void setId(String id) { this.id = id; }
    public void setName(String name) { this.name = name; }
    public void setIngredients(String ingredients) { this.ingredients = ingredients; }
    public void setInstructions(String instructions) { this.instructions = instructions; }

    // overrident methods from Ratable interface
    @Override
    public void rate(double rating) {
        // ensuring rating stays within 0-10 range
        if( rating <= 10.0 && rating >= 0.0) {
            this.rating = rating;
        }
    }
    @Override
    public double getRating() { return rating; }
    
    // required overriding of the equals method
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Recipe recipe = (Recipe) obj;
        return this.id.equals(recipe.id);
    }
    
    // overriden toString
    @Override
    public String toString() {
        return "Recipe [name=" + name + ", rating=" + rating + "]";
    }
}

// Main Cooking Contest class
public class CookingContest {
    private Date contestDate;
    private double prizeMoney;
    private ArrayList<Chef> participants;
    
    public CookingContest(java.util.Date contestDate, double prizeMoney) {
        this.contestDate = contestDate;
        this.prizeMoney = prizeMoney;
        // new empty list
        this.participants = new java.util.ArrayList<>();
    }
    
    // adding and removing chef
    public void addChef(Chef chef) { participants.add(chef); }
    
    public void removeChef(Chef chef) {
        // making sure that the list is not empty
        if(!participants.isEmpty()){
         participants.remove(chef); 
        } else {
            System.out.println("No chefs to remove.");
        }
    }
            
    // getters and setters
    public Date getDate() { return contestDate; }
    public void setDate(java.util.Date date) { this.contestDate = date; }
    
    public double getPrizeMoney() { return prizeMoney; }
    
    public void setPrizeMoney(double amount) { this.prizeMoney = amount; }
    
    // a method to print all ratings of the contest for each chef and recipe
    public void printAllRatings() {
        System.out.println("=== COOKING CONTEST RATINGS ===");
        System.out.println("Contest Date: " + contestDate);
        System.out.println("Prize Money: $" + prizeMoney);
        System.out.println("\n=== CHEFS ===");
        
        for (Chef chef : participants) {
            System.out.println(chef);
            System.out.println("  Recipes:");
            for (Recipe recipe : chef.getRecipes()) {
                System.out.println("    - " + recipe);
            }
            System.out.println();
        }
    }
    
    // demo main method
    public static void main(String[] args) {
        // creating a contest
        CookingContest contest = new CookingContest(new Date(), 5000.0);
        
        // creating senior chefs
        SeniorChef shakeela = new SeniorChef("S001", 25);
        SeniorChef razia = new SeniorChef("S002", 20);
        
        // creating recipes for senior chefs
        Recipe chickenPulao = new Recipe("R001", "Chicken Pulao", "Chicken, Rice, Tomato, Onion", "Boil rice and add chicken");
        Recipe scrambledEggs = new Recipe("R002", "Scrambled Eggs", "Eggs, butter, cream", "Whisk eggs and cook slowly");
        Recipe biryani = new Recipe("R003", "Chicken Biryani", "Rice, Chicken, Tomato", "Cook chicken with spices and layer with rice");
        
        // adding recipes to senior chefs
        shakeela.addRecipe(chickenPulao);
        shakeela.addRecipe(scrambledEggs);
        razia.addRecipe(biryani);
        
        // creating junior chefs with supervisors
        JuniorChef ali = new JuniorChef("J001", shakeela);
        JuniorChef sara = new JuniorChef("J002", razia);
        
        // creating recipes for junior chefs
        Recipe pasta = new Recipe("R004", "pasta", "Pasta, eggs, cheese", "Mix pasta with egg mixture");
        Recipe chocolateCake = new Recipe("R005", "Chocolate Cake", "Flour, sugar, chocolate", "Mix and bake");
        
        // adding recipes to junior chefs
        ali.addRecipe(pasta);
        sara.addRecipe(chocolateCake);
        
        // adding chefs to contest
        contest.addChef(shakeela);
        contest.addChef(razia);
        contest.addChef(ali);
        contest.addChef(sara);
        
        // rating some recipes
        chickenPulao.rate(9.5);
        pasta.rate(8.0);
        biryani.rate(9.2);
        chocolateCake.rate(8.7);
        
        // rating chefs
        shakeela.rate(9.0);
        razia.rate(8.5);
        ali.rate(7.0);
        sara.rate(7.5);
        
        // printing all ratings
        contest.printAllRatings();
    }
}