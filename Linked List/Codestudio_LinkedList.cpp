//https://www.codingninjas.com/studio/problems/introduction-to-linked-list_8144737

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

Node* constructLL(vector<int>& arr) {
    if(arr.empty())
    {
        return nullptr;
    }

    Node *head = new Node(arr[0]);
    Node *curr = head;

    for(int i = 1; i < arr.size(); i++)
    {
        Node* newNode = new Node(arr[i]);

        curr->next = newNode;

        curr = newNode;
    }

    return head;

}