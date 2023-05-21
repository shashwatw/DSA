#include <iostream>
#include "Hero.cpp"
using namespace std;

int main()
{

    Hero Ramesh;
    Ramesh.health = 100;
    Ramesh.level = 'A';

    cout << "Health is: " << Ramesh.health << endl;
    cout << "Level is: " << Ramesh.level << endl;

    return 0;
}