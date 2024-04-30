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