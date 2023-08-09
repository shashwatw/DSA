#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> s;
    string ch;

    cout << "Enter the string: ";
    cin >> ch;

    for (int i = 0; i < ch.length(); i++)
    {
        s.push(ch[i]);
    }

    string ans = "";

    while (!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }

    cout << "Reversed string is: " << ans;

    return 0;
}