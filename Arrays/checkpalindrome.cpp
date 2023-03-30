// #include <iostream>
// using namespace std;

// void reverse(string s, string s1)
// {
//     int n = s.size() - 1;
//     for (int i = 0; i < n; i++)
//     {
//         swap(s[i], s[n]);
//         n--;
//     }
//     if (s == s1)
//     {
//         cout << "Palindrome" << endl;
//     }
//     else
//     {
//         cout << "Not Palindrome" << endl;
//     }
// }

// int main()
// {
//     string s = "amanaplanacanalpanama";
//     string s1 = s;
//     reverse(s, s1);

//     return 0;
// }

#include <iostream>
using namespace std;

char toLowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
    return ch;
}

bool checkpalin(char s[], int n)
{
    int strt = 0;
    int end = n - 1;

    while (strt <= end)
    {
        if (toLowerCase(s[strt]) != toLowerCase(s[end]))
        {
            return false;
        }
        else
        {
            strt++;
            end--;
        }
    }
    return true;
}

int getlength(char s[])
{
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char s[50];
    cout << "Enter the string: ";
    cin >> s;

    int len = getlength(s);

    cout << "Length: " << len << endl;

    cout << "Palindrome or not: " << checkpalin(s, len) << endl;
    // cout << "Check: " << toLowerCase(s) << endl;

    return 0;
}