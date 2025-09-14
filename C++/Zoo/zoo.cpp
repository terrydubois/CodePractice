#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Animal {

protected:
    string name;
    int age;

public:

    // constructor
    Animal(const string& name, int age) :
        name(name),
        age(age)
        {}

    // virtual function speak
    virtual void speak() const = 0;

};

class Dog : public Animal {

public:

    Dog(const string& name, int age) :
        Animal(name, age)
        {}

    void speak() const override {
        cout << "Dog " << name << " says woof!" << endl;
    }
};

class Cat : public Animal {

public:

    Cat(const string& name, int age) :
        Animal(name, age)
        {}
    
    void speak() const override {
        cout << "Cat " << name << " says meow!" << endl;
    }
};

int main() {

    vector<Animal*> animals;
    animals.push_back(new Dog("Bailey", 10));
    animals.push_back(new Cat("Tibbs", 2));
    animals.push_back(new Cat("Periwinkle", 2));

    for (Animal* animal : animals) {
        animal->speak();
    }
}