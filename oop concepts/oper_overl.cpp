#include <iostream>
using namespace std;

class A
{
public:
    int a;
    int b;

public:
    int add()
    {
        return a + b;
    }

    void operator+(A &obj)
    {
        int val1 = this->a;
        int val2 = obj.a;
        cout << "Output is : " << val2 - val1 << endl;
    }
    void operator()()
    {
        cout << "Brackets have been used " << this->a << endl;
    }
};
int main()
{
    A obj1, obj2;
    obj1.a = 4;
    obj2.a = 9;

    obj1 + obj2;
    obj1();
    // cout << obj.add() << endl;
    return 0;
}