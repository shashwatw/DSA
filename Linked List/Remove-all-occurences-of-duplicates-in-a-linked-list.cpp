//* https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1

// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution
{
public:
    Node *removeAllDuplicates(struct Node *head)
    {

        if (head == NULL || head->next == NULL)
            return head;

        Node *prev = head;
        Node *curr = head;

        while (curr != NULL && curr->next != NULL)
        {

            Node *nextNode = curr->next;

            if (nextNode->data != curr->data)
            {
                prev = curr;
                curr = curr->next;
            }

            else
            {

                if (curr == head)
                {
                    while (head != NULL && head->data == nextNode->data)
                    {
                        head = head->next;
                    }
                    curr = head;
                    prev = curr;
                }
                else
                {
                    while (nextNode != NULL && nextNode->data == curr->data)
                    {
                        Node *dump = nextNode;
                        nextNode = nextNode->next;
                        delete dump;
                    }
                    curr = nextNode;
                    prev->next = curr;
                }
            }
        }

        return head;
    }
};