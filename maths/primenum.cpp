#include <iostream>
using namespace std;

int num;
bool isPrimeNum(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << "Enter a number: ";
    cin >> num;

    if (isPrimeNum(num))
    {
        cout << "Prime Number";
    }
    else
    {
        cout << "Not a Prime Number";
    }
    return 0;
}