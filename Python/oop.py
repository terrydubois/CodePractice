class Animal:

    def __init__(self, name: str, age: int):
        self.name = name
        self.age = age
        print("Animal created!")

    def make_sound(self):
        print("Animal sound!")

    def say_age(self):
        print(f"I am {self.age} years old!")

class Cat(Animal):

    def make_sound(self):
        print("meow!")

if __name__ == "__main__":

    periwinkle = Cat("Periwinkle", 2)
    periwinkle.make_sound()
    periwinkle.say_age()