#include <iostream>
using namespace std;

class Human
{
public:
    int age;
    int height;
    int weight;

public:
    int getAge()
    {
        return this->age;
    }
    void setWeight(int weight)
    {
        this->weight = weight;
    }
};

class Male : protected Human
{
public:
    string color;
    void sleep()
    {
        cout << "MALE Sleeping" << endl;
    }

    int getHeight()
    {
        return this->height;
    }
};

int main()
{
    Male m1;
    cout << m1.getHeight() << endl;
    /*
    Male object1;
    cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;
    cout << object1.color << endl;
    object1.setWeight(99);
    cout << object1.weight << endl;
    object1.sleep();
    */

    return 0;
}