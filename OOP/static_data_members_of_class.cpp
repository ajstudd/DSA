#include <iostream>
using namespace std;
// *Static members belong to the class itself, not individual objects.

// *Static Data Members: Shared across all objects; memory is allocated once.

// *Static Member Functions: Can access only static members.

class Car
{
public:
    static int carCount; // Declaration of static variable
    int publicVal = 8;
    Car()
    {
        carCount++; // Increment count whenever an object is created
    }

    static void memberfunc()
    {
        cout << carCount;
        // cout << "Public val" << publicVal; INFO: Static member cannot access normal class members
    }
};

// Define and initialize static variable outside the class, we are using scope resolution operator here
// INFO: Scope resolution is used to specify the scope (or "ownership") of a function, variable, or class member.
int Car::carCount = 0;
// You're saying:
// “Hey C++, I’m defining the static variable carCount that belongs to the Car class.”
// *Why Not Initialize in Class?
// You cannot initialize non-const static members inside the class (in C++98/03/11/14),
// because they live outside the object’s memory — they are shared among all instances.

int main()
{
    Car car1, car2, car3;
    cout << "Total Cars: " << Car::carCount << endl; // Access without an object
    car1.memberfunc();

    return 0;
}
