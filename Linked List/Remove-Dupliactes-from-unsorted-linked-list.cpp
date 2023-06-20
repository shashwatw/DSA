/*Program to remove duplicates in an unsorted linked list*/
#include <bits/stdc++.h>
using namespace std;
/* A linked list node has a value and a pointer to the next node*/
class Node
{
public:
    int val;
    Node *next;
};
/* Function to create a new Node*/
Node *newNode(int new_val)
{
    Node *temp = new Node;
    temp->val = new_val;
    temp->next = NULL;
    return temp;
}
/* Function to append a new node at the end. - Given a reference (pointer to
 * pointer) to the head of a list and an int */
void append(Node **head_ref, int new_val)
{
    /* Create a new node */
    Node *new_node = new Node();
    Node *last = *head_ref;
    /* Insert the data */
    new_node->val = new_val;
    /* Make the text of this node NULL*/
    new_node->next = NULL;
    /* If the Linked List is empty, then make a new node as head*/
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    /*  else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next;
    }
    /*  Change the next of last node */
    last->next = new_node;
    return;
}
/* Function to remove duplicates from linked list */
void remove_duplicates(Node *head)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        /* Compare the picked element with the rest of the elements in the inner
         * loop. */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->val == ptr2->next->val)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else /* if not duplicate move to next node */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
/* Function to print nodes in a given linked list */
void printLinkedList(Node *node)
{
    while (node->next)
    {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("%d ", node->val);
}

/* Driver code */
int main()
{
    /* Start with the empty list */
    Node *head = NULL;
    int size = 8;

    int arr[8] = {1, 5, 8, 6, 1, 7, 5, 4};

    for (int i = 0; i < size; i++)
    {
        append(&head, arr[i]);
    }

    printf("Original Linked List:\n");
    printLinkedList(head);
    remove_duplicates(head);
    printf("\nLinked list after removing duplicates:\n");
    printLinkedList(head);
    return 0;
}