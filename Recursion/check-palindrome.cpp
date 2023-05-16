#include <iostream>
using namespace std;

bool checkPalindrome(string str, int i, int j)
{
    if (i > j)
        return true;
    if (str[i] != str[j])
        return false;

    return checkPalindrome(str, i + 1, j - 1);
}

int main()
{

    string str = "racecar";

    int n = str.length();

    bool isPalindrome = checkPalindrome(str, 0, n - 1);

    if (isPalindrome)
        cout << "Yes, it is a palindrome";
    else
        cout << "No, it is not a palindrome";

    return 0;
}