#include <iostream>
#include <stack>
using namespace std;
int main()
{
    // creation of stack
    stack<int> s;

    // push operation
    s.push(2);
    s.push(3);

    // pop
    s.pop();

    cout << "Printing the top element: " << s.top() << endl;

    if (s.empty())
    {
        cout << "Stack is empty";
    }
    else
    {
        cout << "Stack is not empty";
    }

    return 0;
}