//^ https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1

/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution
{
public:
    bool isVowel(char data)
    {
        if (data == 'a' || data == 'e' || data == 'i' || data == 'o' || data == 'u')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node *arrangeCV(Node *head)
    {
        // Code here
        Node *vowelHead = new Node(0);
        Node *consonantHead = new Node(0);

        Node *vowelTail = vowelHead;
        Node *consonantTail = consonantHead;

        Node *curr = head;

        while (curr != NULL)
        {
            if (isVowel(curr->data))
            {
                vowelTail->next = curr;
                vowelTail = curr;
            }
            else
            {
                consonantTail->next = curr;
                consonantTail = curr;
            }

            curr = curr->next;
        }

        vowelTail->next = consonantHead->next;
        consonantTail->next = NULL;

        head = vowelHead->next;

        delete vowelHead;
        delete consonantHead;

        return head;
    }
};