#include <iostream>

using namespace std;

/* Linked list node */
class Node {
public:
    int data;
    Node* next;
};

/* Function to create a new node with given data */
Node* newNode(int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

/* Function to add two numbers represented by linked lists */
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* head = nullptr;
    Node* current = nullptr;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;

        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum %= 10;

        Node* new_node = newNode(sum);

        if (head == nullptr) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = current->next;
        }
    }

    return head;
}

/* A utility function to print a linked list */
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

/* Driver program to test above function */
int main() {
    // Create linked list 1: 2 -> 4 -> 3
    Node* l1 = newNode(2);
    l1->next = newNode(4);
    l1->next->next = newNode(3);

    // Create linked list 2: 5 -> 6 -> 4
    Node* l2 = newNode(5);
    l2->next = newNode(6);
    l2->next->next = newNode(4);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    Node* sum = addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printList(sum);

    return 0;
}
