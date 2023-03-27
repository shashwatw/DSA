#include <iostream>
using namespace std;

long long int mySqrt(int x)
{
    long long int l, h, mid;
    long long int ans = -1;
    l = 0;
    h = x;
    mid = (l + h) / 2;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (mid * mid < x)
        {
            l = mid + 1;
            ans = mid;
        }
        else if (mid * mid == x)
        {
            return (mid);
        }
        else
        {
            h = mid - 1;
        }
    }
    return (ans);
}

double morePrecision(int n, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;

        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n, precision;
    cout << "Enter the number: " << endl;
    cin >> n;
    cout << "Enter the precision: " << endl;
    cin >> precision;

    int tempSol = mySqrt(n);
    double ans = morePrecision(n, precision, tempSol);
    cout << ans << endl;
    return 0;
}