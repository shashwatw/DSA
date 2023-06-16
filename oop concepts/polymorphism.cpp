#include <iostream>
using namespace std;
// Function Overloading
class A
{
public:
    void sayHello()
    {
        cout << "Hello Shashwat Wankhedekar" << endl;
    }
    void sayHello(string name)
    {
        cout << "Hello " << name << endl;
    }
    void sayHello(char name)
    {
        cout << "Hello character " << name << endl;
    }
};
int main()
{
    A obj1;
    obj1.sayHello();
    obj1.sayHello("Ally");
    obj1.sayHello("s");
    return 0;
}