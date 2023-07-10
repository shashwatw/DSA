#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *rotate(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head; // No rotation needed
    }

    Node *prev = nullptr;
    Node *current = head;
    while (current->next != nullptr)
    {
        prev = current;
        current = current->next;
    }

    prev->next = nullptr; // Disconnect the last element from the list
    current->next = head; // Connect the last element to the old head

    return current; // Return the new head (last element)
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Node *result = rotate(head);
        print(result);
        cout << endl;
    }
    return 0;
}
