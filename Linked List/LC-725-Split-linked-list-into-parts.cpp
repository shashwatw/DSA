//* https://leetcode.com/problems/split-linked-list-in-parts/description/

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int cnt = 0;
        ListNode *temp = head;
        vector<ListNode *> res;

        // Calculate the length of the linked list
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }

        temp = head;

        // Case when the number of nodes is less than or equal to k
        if (cnt <= k)
        {
            while (k != 0)
            {
                if (cnt <= 0)
                {
                    res.push_back(NULL); // Add NULL if there are fewer nodes than parts
                }
                else
                {
                    ListNode *temp2 = temp->next;
                    res.push_back(temp); // Add the node to the result
                    temp->next = NULL;   // Disconnect the node
                    temp = temp2;        // Move to the next node
                }
                cnt--;
                k--;
            }
            return res;
        }

        // Calculate the number of larger and smaller parts
        int cnttype1 = cnt % k;      // Parts that need an extra node
        int lentype1 = cnt / k + 1;  // Length of larger parts
        int cnttype2 = k - cnttype1; // Parts with the base length
        int lentype2 = cnt / k;      // Length of smaller parts

        temp = head;
        // handling the larger parts
        for (int i = 0; i < cnttype1; ++i)
        {
            ListNode *partHead = temp;
            ListNode *prev = nullptr;
            for (int j = 0; j < lentype1; ++j)
            {
                prev = temp;
                temp = temp->next;
            }
            if (prev)
                prev->next = NULL;
            res.push_back(partHead);
        }

        // handling the smaller parts
        for (int i = 0; i < cnttype2; ++i)
        {
            ListNode *partHead = temp;
            ListNode *prev = nullptr;
            for (int j = 0; j < lentype2; ++j)
            {
                prev = temp;
                temp = temp->next;
            }
            if (prev)
                prev->next = NULL;
            res.push_back(partHead);
        }

        return res;
    }
};
