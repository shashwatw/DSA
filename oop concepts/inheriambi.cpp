#include <iostream>
using namespace std;

class A
{
public:
    void func()
    {
        cout << "I am A" << endl;
    }
};

class B
{
public:
    void func()
    {
        cout << "I am B" << endl;
    }
};

class C : public A, public B
{
};

int main()
{
    C obj1;
    obj1.A::func();
    obj1.B::func();

    return 0;
}