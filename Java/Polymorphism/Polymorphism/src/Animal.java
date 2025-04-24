public abstract class Animal {

    String name;

    public Animal(String name) {
        this.name = name;
    }

    public void makeSound() {
        System.out.println("Animal sound!");
    }
}
