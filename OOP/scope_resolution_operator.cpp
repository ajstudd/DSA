#include <iostream>
using namespace std;
// INFO: Scope resolution is used to specify the scope (or "ownership") of a function, variable, or class member.
// Uses of Scope resolution operator.
// | Use Case                                    | Example             | Meaning                                        |
// | ------------------------------------------- | ------------------- | ---------------------------------------------- |
// | **Accessing static class members**          | `Car::carCount`     | Refers to a static variable in `Car`           |
// | **Accessing global variable when shadowed** | `::x`               | Refers to global `x`, not local one            |
// | **Namespace resolution**                    | `std::cout`         | Accesses `cout` in the `std` namespace         |
// | **Class function definition outside class** | `void Car::drive()` | Defines `drive()` from `Car` outside the class |

// 🌍 1. Global Variable
int value = 100;

class MyClass
{
public:
    // 🏗️ 2. Static Variable Declaration (Definition will be outside)
    static int count;

    // 🚗 3. Member Function declared inside, defined outside using ::
    void showMessage();

    void accessGlobalAndLocal()
    {
        int value = 50; // Local variable shadows global

        cout << "Local value: " << value << endl;
        cout << "Global value using ::value: " << ::value << endl; // Resolves to global scope
    }

    // ⚙️ 4. Static Function can also use scope resolution from outside
    static void displayStatic();
};

// 🧮 2. Static Variable Definition using scope resolution operator
int MyClass::count = 0;

// 🛠️ 3. Member Function Definition using scope resolution
void MyClass::showMessage()
{
    cout << "Hello from MyClass::showMessage()" << endl;
}

// 🧾 4. Static Function defined using ::
void MyClass::displayStatic()
{
    cout << "Static variable count is: " << count << endl;
}

namespace Custom
{
    void greet()
    {
        cout << "Greetings from Custom::greet()" << endl;
    }
}

int main()
{
    cout << "=== Demonstrating Scope Resolution Operator ===\n\n";

    // ✅ 1. Accessing global variable when a local one shadows it
    MyClass obj;
    obj.accessGlobalAndLocal();

    cout << "\n";

    // ✅ 2. Calling member function defined outside using ::
    obj.showMessage();

    cout << "\n";

    // ✅ 3. Accessing static variable using ClassName::variable
    MyClass::count = 42;
    MyClass::displayStatic();

    cout << "\n";

    // ✅ 4. Calling function in a namespace using ::
    Custom::greet();

    return 0;
}
