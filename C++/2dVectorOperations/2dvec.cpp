#include <iostream>
#include <cmath>

using namespace std;

class Vector2D {

public:
    // variables
    double x, y;

    // constructor
    Vector2D(double x, double y)
    : x(x), y(y) {}

    // vector addition
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // scalar multiplication
    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    // dot product
    double dot(const Vector2D& other) const {
        return (x * other.x) + (y * other.y);
    }

    // magnitude
    double magnitude() const {
        return sqrt((x * x) + (y * y));
    }

    // normalize
    Vector2D normalize() const {
        double mag = magnitude();

        // make sure we don't divide by zero
        if (mag == 0) return Vector2D(0, 0);

        return Vector2D(x / mag, y / mag);
    }

    // print x & y values
    void printVals() const {
        cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {

    // create vectors
    Vector2D a(3, 4);
    Vector2D b(1, 2);
    cout << "a: ";
    a.printVals();
    cout << "b: ";
    b.printVals();

    // add a + b
    Vector2D sum = a + b;
    cout << "sum: ";
    sum.printVals();

    // multiply a by 2
    Vector2D aScaled = a * 2;
    cout << "a * 2: ";
    aScaled.printVals();

    // dot product of a and b
    double dot = a.dot(b);
    cout << "dot product: " << dot << endl;

    // magnitude of a
    double aMag = a.magnitude();
    cout << "magnitude of a: " << aMag << endl;

    // normalize a
    Vector2D aNormalized = a.normalize();
    cout << "a normalized: ";
    aNormalized.printVals();
}