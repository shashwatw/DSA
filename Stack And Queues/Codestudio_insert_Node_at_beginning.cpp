//https://www.codingninjas.com/studio/problems/insert-node-at-the-beginning_8144739

/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */

Node* insertAtFirst(Node* list, int newValue) {
    // Create a new node with the given value
    Node* newNode = new Node(newValue);

    // Set the next pointer of the new node to the current head
    newNode->next = list;

    // Update the head to point to the new node
    list = newNode;

    return list; // Return the new head of the linked list
}
