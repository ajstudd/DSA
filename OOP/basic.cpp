#include <iostream>
using namespace std;

class Abc
{
private:
    int privateVal;

public:
    string ab;
    int numb;
    Abc(string st, int n, int priv)
    {
        this->ab = st;
        this->numb = n;
        privateVal = priv;
    }
    void print()
    {
        cout << "AB is: " << this->ab << endl;
        cout << "Numb is: " << this->numb << endl;
        cout << "Private is: " << privateVal << endl;
    }
};
int main()
{
    // stack allocation
    Abc anObject("hello", 123, 456);
    anObject.print();
    anObject.numb = 546;
    // anObject.privateVal = 546; INFO: Private variable will not be accessible
    anObject.print();
    // pointer method or we can say heap allocation
    Abc *ptr = new Abc("Junaid", 786, 876);
    cout << ptr->ab << endl;
    cout << ptr->numb << endl;
    ptr->print();
    return 0;
}