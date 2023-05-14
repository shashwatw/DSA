#include <iostream>
using namespace std;

void sayDigit(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }
    else
    {

        int digit = n % 10;
        n = n / 10;
        sayDigit(n, arr);
        cout << arr[digit] << " ";
    }
}

int main()
{

    cout << "Enter a number: ";

    int n;
    cin >> n;

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    sayDigit(n, arr);

    return 0;
}