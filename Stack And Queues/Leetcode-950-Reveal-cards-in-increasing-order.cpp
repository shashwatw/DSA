// https://leetcode.com/problems/reveal-cards-in-increasing-order/description/

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {

        sort(rbegin(deck), rend(deck));
        deque<int> dq;
        int n = deck.size();
        dq.push_front(deck[0]);
        for (int i = 1; i < n; i++)
        {
            // Take the top card from the back of the deque
            int x = dq.back();
            // Remove this card from the deque
            dq.pop_back();
            // Place this revealed card at the front of the deque
            dq.push_front(x);
            // Add the current card from the sorted deck to the front of the deque
            dq.push_front(deck[i]);
        }
        // Retrieve the revealed cards in increasing order
        vector<int> ans;
        while (!dq.empty())
        {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        // Return the ordered deck
        return ans;
    }
};