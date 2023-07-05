// https://www.codingninjas.com/studio/problems/flatten-a-linked-list_1112655?source=youtube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTab=0

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    Node *result;

    if (a->data < b->data)
    {
        result = a;
        result->child = merge(a->child, b);
    }
    else
    {
        result = b;
        result->child = merge(a, b->child);
    }

    result->next = NULL;
    return result;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    head->next = flattenLinkedList(head->next);

    head = merge(head, head->next);

    return head;
}
