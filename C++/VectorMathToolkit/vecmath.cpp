#include <iostream>

using namespace std;

class Vector3 {

public:
    // member variables
    float x;
    float y;
    float z;

    // constructor
    Vector3(const float x, const float y, const float z)
    : x(x), y(y), z(z) {}

    // print Vector3 variables
    void printXYZ() const {
        cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
    }
};

Vector3 add(const Vector3& vecA, const Vector3& vecB) {
    return Vector3(vecA.x + vecB.x, vecA.y + vecB.y, vecA.z + vecB.z);
}

Vector3 subtract(const Vector3& vecA, const Vector3& vecB) {
    return Vector3(vecA.x - vecB.x, vecA.y - vecB.y, vecA.z - vecB.z);
}

float dot(const Vector3& vecA, const Vector3& vecB) {
    return vecA.x * vecB.x + vecA.y * vecB.y + vecB.z * vecB.z;
}

Vector3 cross(const Vector3& vecA, const Vector3& vecB) {
    return Vector3(
        ((vecA.y * vecB.z) - (vecA.z * vecB.y)),
        ((vecA.x * vecB.z) - (vecA.z * vecB.x)),
        ((vecA.x * vecB.y) - (vecA.y * vecB.x))
    );
}

int main() {

    Vector3 vecA(1, 3, 4);
    Vector3 vecB(2, 7, -5);

    cout << "inputs:" << endl;
    vecA.printXYZ();
    vecB.printXYZ();

    cout << "add:" << endl;
    Vector3 vecResultAdd = add(vecA, vecB);
    vecResultAdd.printXYZ();

    cout << "subtract:" << endl;
    Vector3 vecResultSubtract = subtract(vecA, vecB);
    vecResultSubtract.printXYZ();

    float vecResultDot = dot(vecA, vecB);
    cout << "dot: " << vecResultDot << endl;

    cout << "cross:" << endl;
    Vector3 vecResultCross = cross(vecA, vecB);
    vecResultCross.printXYZ();

}