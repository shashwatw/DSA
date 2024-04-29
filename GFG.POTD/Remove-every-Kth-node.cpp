//^ https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

/* Link list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution
{
public:
    Node *deleteK(Node *head, int K)
    {
        // Your code here
        if (head == NULL || K <= 1)
            return NULL;

        Node *prev = head;
        Node *curr = head;
        int cnt = 0;

        while (curr != NULL)
        {
            cnt++;

            if (cnt % K == 0)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};