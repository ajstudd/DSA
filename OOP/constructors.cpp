#include <iostream>
using namespace std;

class Car
{
public:
    string brand;
    string model;
    int year;

    // Default Constructor
    Car()
    {
        brand = "Unknown";
        model = "Unknown";
        year = 0;
    }

    // Parameterized Constructor
    Car(string b, string m, int y)
    {
        brand = b;
        model = m;
        year = y;
    }

    // 📌 Copy Constructor
    Car(const Car &other)
    {
        brand = other.brand;
        model = other.model;
        year = other.year;
        cout << "Copy constructor called!" << endl;
    }

    void displayInfo()
    {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
    }
};

int main()
{
    Car car1("Ford", "Mustang", 2022); // Parameterized constructor
    Car car2 = car1;                   // 🚀 Copy constructor called here

    car1.displayInfo();
    car2.displayInfo();

    return 0;
}
