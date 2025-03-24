#include <iostream>
#include <vector>

using namespace std;

class Cat {
public:
	Cat(string _name, int _age) {
		this->name = _name;
		this->age = _age;
	}
	int getAge() {
		return this->age;
	}
	void setAge(int _age) {
		this->age = _age;
	}
	string getName() {
		return this->name;
	}
	void display() {
		cout << "Cat's name: " << name << ", Cat's age: " << age << endl;
	}
private:
	string name;
	int age;
};

class Person {
public:
	Person(string _name, int _age) {
		this->name = _name;
		this->age = _age;
	}

	void addCat(Cat* cat) {
		cats.push_back(cat);
	}


	void display() {
		cout << "Name: " << this->name << ", Age: " << this->age << endl;
		cout << "Cats:\n";
		for (int i = 0; i < cats.size(); i++) {
			Cat* cat = cats[i];
			cat->display();
		}
	}
private:
	string name;
	int age;
	vector<Cat*> cats;
};


int main() {

	cout << "Hello world!\n";

	Cat* tibbs = new Cat("Tibbs", 1);
	Cat* peri = new Cat("Periwinkle", 1);

	Person terry("Terry", 28);
	terry.addCat(tibbs);
	terry.addCat(peri);
	terry.display();

	tibbs->setAge(2);
	cout << "Changed Tibbs' age to 2\n";
	terry.display();

	return 0;
}

