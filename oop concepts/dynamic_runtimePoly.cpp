#include <iostream>
using namespace std;
// dynamic polymorphism ====> function overriding
// in this the class having the same function will be called as it would be more relevant for it to execute

class Animal
{
public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Barking" << endl;
    }
};

int main()
{
    Dog d;
    d.speak();
    return 0;
}