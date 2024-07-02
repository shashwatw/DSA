//* https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1

/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
private:
    bool isPalindrome(string &s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

public:
    bool compute(Node *head)
    {
        // Your code goes here
        string s = "";
        Node *temp = head;

        while (temp != NULL)
        {
            s += temp->data;
            temp = temp->next;
        }

        return isPalindrome(s);
    }
};