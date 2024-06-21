//^ https://www.geeksforgeeks.org/problems/word-ladder/1

//* Intuition
//* We made a an unordered set and copied wordList's value to it
//* Then we will push the startword with the initial step as 1 in the queue and remove startWord from set
//* Now we will do a brute force approach where we will check for each char of the word replacing it with 26 alphabets and if someone matches the wordList we will push it again in queue and erase from set
//* Finally when we encounter q's popped word as target word we will return its steps

//& TC - O(Number of words * wordlength * 26)
//& SC - O(N) {queue}

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Code here
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({startWord, 1});
        st.erase(startWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

//* BRUTE FORCE APPROACH (infeasible here for larger inputs)

//^ Explanation:
//^ Initialization:

//^ A set wordSet is created from the wordList for quick lookup.
//^ minLength is initialized to INT_MAX to track the minimum length of the transformation sequence.

//^& Brute Force Helper Function:

//^ The bruteForce function tries all possible one-letter transformations recursively.
//^ If the current word matches the endWord, the number of steps is compared with minLength.
//^ The function iterates over each character of the current word, changing it to every other possible character from 'a' to 'z'.
//^ If the transformed word is in the wordSet, it is removed from the set (to avoid cycles) and the function recursively tries the next transformation.
//^ After exploring all possibilities, the word is added back to the set (backtracking).

//& Main Function:

//^ If endWord is not in the wordList, it returns 0 as no transformation is possible.
//^ Calls the bruteForce function starting from the beginWord.

//& Output:

//^ If minLength remains INT_MAX, it means no transformation sequence was found, so it returns 0.
//^ Otherwise, it returns the minLength found.
//! Note:
//! This brute force approach is not practical for larger inputs because it generates and checks all possible sequences, leading to exponential time complexity. The BFS approach provided earlier is significantly more efficient and suitable for this problem.

class Solution
{
public:
    int minLength = INT_MAX;

    // Helper function to recursively try all transformations
    void bruteForce(string currentWord, string endWord, unordered_set<string> &wordSet, int steps)
    {
        if (currentWord == endWord)
        {
            minLength = min(minLength, steps);
            return;
        }

        string originalWord = currentWord;
        for (int i = 0; i < currentWord.size(); ++i)
        {
            char originalChar = currentWord[i];
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (c == originalChar)
                    continue;
                currentWord[i] = c;
                if (wordSet.find(currentWord) != wordSet.end())
                {
                    wordSet.erase(currentWord);
                    bruteForce(currentWord, endWord, wordSet, steps + 1);
                    wordSet.insert(currentWord); // Backtrack
                }
            }
            currentWord[i] = originalChar; // Restore original word
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
        {
            return 0; // If endWord is not in wordList, no transformation is possible
        }

        bruteForce(beginWord, endWord, wordSet, 1);
        return minLength == INT_MAX ? 0 : minLength;
    }
};
