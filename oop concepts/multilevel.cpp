#include <iostream>
using namespace std;

class Animal
{
public:
    int age;
    int weight;

public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal
{
};

class germanshepherd : public Dog
{
};

int main()
{
    germanshepherd g;

    g.speak();
    cout << g.age << endl;

    return 0;
}