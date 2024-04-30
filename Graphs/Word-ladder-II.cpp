//^ https://www.geeksforgeeks.org/problems/word-ladder-ii/1

//* INTUITION
//* Here we want to return all the sequences which take minimum steps to reach endword
//* Here we made a queue of vector of strings to store all the sequences
//* we also copied wordlist into unordered set
//* initally we made a vector of string usedOnLevel vector to store the strings levelwise
//* push beginning word to q and to usedOnLevel vector
//* initially q is empty so level is 0
//* Now we will call bfs and make a while loop to work till q is empty
//* if vector is of size 1 then it is of level 1
//* if vector is of size k then it is of level k
//* we will check if the size of popped vector is greater than level
//* If yes then inc level and that means prev level is completed so erase the element from set
//* if the last word of vec is endword then check uf ans vec is empty....if empty push it and if not then check that what is the size of that vec because it is the steps...if one more vec is of same size then is potential possible answers so push back into ans vector
//* Now take last word from the vec popped from queue and check for each permutations of characters and check that formed word is in set
//* Now do the needful and push it in q and pop it again after pushing in q to let same level permuation can go in same level

//& TC - O(Impossible to calc) {depends on the words}

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        // code here
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;

        q.push({beginWord});
        vector<string> usedOnLevel;

        usedOnLevel.push_back(beginWord);

        int level = 0;
        vector<vector<string>> ans;

        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = vec.back();

            // store the ans
            if (word == endWord)
            {
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }

            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    // found the word in set
                    if (st.count(word) > 0)
                    {
                        vec.push_back(word);
                        q.push(vec);

                        // mark as visited on the levels
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};