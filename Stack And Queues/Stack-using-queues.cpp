//https://www.codingninjas.com/studio/problems/stack-using-queue_795152?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

#include <iostream>
#include <queue>

using namespace std;

class Stack {
private:
    queue<int> q1, q2; // Two queues to simulate the stack

public:
    Stack() {
        // Constructor
    }

    int getSize() {
        return q1.size(); // The size of the stack is the size of q1
    }

    bool isEmpty() {
        return q1.empty(); // The stack is empty if q1 is empty
    }

    void push(int element) {
        q2.push(element); // Push the new element into q2

        // Move elements from q1 to q2, maintaining the order
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the names of q1 and q2 to keep q1 as the main stack
        swap(q1, q2);
    }

    int pop() {
        if (isEmpty()) {
            return -1; // Return a default value
        }

        int topElement = q1.front(); // Get the top element
        q1.pop(); // Remove the top element
        return topElement;
    }

    int top() {
        if (isEmpty()) {
            return -1; // Return a default value
        }

        return q1.front(); // Return the top element
    }
};