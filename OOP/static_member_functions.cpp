#include <iostream>
using namespace std;
class Car
{
private:
    static int carCount; // Private static member

public:
    Car() { carCount++; }

    static void showCarCount()
    { // Static method
        cout << "Total Cars: " << carCount << endl;
    }
};

int Car::carCount = 0;

int main()
{
    Car car1, car2;
    Car::showCarCount(); // Call static function without an object

    return 0;
}

// Static variables are shared across all objects.

// Static functions cannot access non-static members.

// Useful for counters, configuration settings, and managing shared data.