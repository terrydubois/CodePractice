#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Vector3 {

public:

    // Vector3 variables
    float x, y, z;

    // constructor
    Vector3(float x=0.0, float y=0.0, float z=0.0)
    : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3& other) const {

        // to add, add the matching variables in each vector
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator*(float scalar) const {

        // to multiply by a scalar, multiply each component by the scalar
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    float dot(const Vector3& other) const {

        // to get dot product, multiplying the matching components of both vectors
        // and then add everything together
        return (x * other.x) + (y * other.y) + (z * other.z);
    }

    double magnitude() const {

        // to get magnitude, take the square root of the sum of
        // the squares from each component
        return sqrt(x*x + y*y + z*z);
    }

    Vector3 normalize() const {

        // get magnitude
        double mag = magnitude();

        // to normalize, divide each component of this vector by the magnitude
        // if magnitude is 0, just return a zero vector
        return (mag == 0) ? Vector3(0, 0, 0) : (*this) * (1.0 / mag);
    }

    void print() const {
        cout << fixed << setprecision(2)
        << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

};

int main() {

    // start an object at position 0, 0, 0
    // with initial velocity 10, 10, 0
    // and gravity 0, -9.8, 0
    Vector3 initPos(0, 0, 0);
    Vector3 initVelocity(10, 10, 0);
    Vector3 gravity(0, -9.8, 0);

    // update position of every 0.1 seconds for 2 seconds
    float timeStep = 0.1;
    float timeTotal = 2.0;
    for (float t = 0.0; t <= timeTotal; t += timeStep) {

        // get current displacement
        Vector3 displacement = (initVelocity * t) + (gravity * 0.5 * t * t);

        // add current displacement to initial position to get current position
        Vector3 pos = initPos + displacement;

        pos.print();
    }
}