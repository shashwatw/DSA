#include <iostream>
using namespace std;

int expo(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    int ans = expo(a, b / 2);

    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return ans * ans * a;
    }
}

int main()
{
    int a = 3, b = 10;

    int ans = expo(a, b);

    cout << a << " to the power " << b << " is: " << ans << endl;
    return 0;
}