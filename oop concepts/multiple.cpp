#include <iostream>
using namespace std;

class Animal
{
public:
    int age;
    int weight;

public:
    void bark()
    {
        cout << "Barking" << endl;
    }
};

class Human
{
public:
    string color;

public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

// multiple inheritance

class Hybrid : public Animal, public Human
{
};

int main()
{
    Hybrid obj;

    obj.speak();
    obj.bark();
    cout << obj.color << endl;
    cout << obj.age << endl;

    return 0;
}