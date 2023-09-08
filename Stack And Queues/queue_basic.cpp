#include<iostream>
#include<queue>

using namespace std;
int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << "Front element " << q.front() << endl;
    q.pop();
    cout << "Front element " << q.front() << endl;
    cout << "Size of queue " << q.size() << endl;
    cout << "Empty or not " << q.empty() << endl;

    q.pop();
    q.pop();   
    q.pop();
    cout << "Empty or not " << q.empty() << endl;

return 0;
}