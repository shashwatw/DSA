// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-heap/problem/rearrange-characters5322

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//*******************************************************************MAIN CODE Starts**************************************
class Solution
{
public:
    // Function to rearrange the characters in a string such that
    // no two adjacent characters are same.
    string rearrangeString(string str)
    {
        // Your code here
        unordered_map<char, int> freq;

        for (auto x : str)
        {
            freq[x]++;
        }

        // maxheap
        priority_queue<pair<int, char>> pq;
        for (auto it : freq)
        {
            pq.push({it.second, it.first});
        }

        string res = "";
        while (!pq.empty())
        {
            // Extract the character with the highest frequency
            pair<int, char> a = pq.top();
            pq.pop();

            // Append the character to the result string
            res += a.second;

            // Decrement the frequency of the character in the frequency map
            freq[a.second]--;

            // Extract the character with the second highest frequency
            if (!pq.empty()) // Check if the priority queue is not empty
            {
                pair<int, char> b = pq.top();
                pq.pop();

                // Append the character to the result string
                res += b.second;

                // Decrement the frequency of the character in the frequency map
                freq[b.second]--;

                // If the frequency of character 'a' or 'b' is greater than 0,
                // push it back into the priority queue
                if (freq[a.second] > 0)
                {
                    pq.push({freq[a.second], a.second});
                }

                if (freq[b.second] > 0)
                {
                    pq.push({freq[b.second], b.second});
                }
            }
        }
        return res;
    }
};

//*******************************************************************MAIN CODE END****************************************

//{ Driver Code Starts.

int checker(string str, string pat)
{
    int freq[26];
    for (int i = 0; i < 26; i++)
        freq[i] = 0;
    if (str.length() != pat.length())
        return 0;
    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i] - 97]--;
        if (pat[i] < 97 || pat[i] > 122)
            return 0;
        freq[pat[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
        if (freq[i] != 0)
            return 0;
    for (int i = 0; i < pat.length() - 1; i++)
        if (pat[i] == pat[i + 1])
            return 0;
    return 1;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string str, ret;
        cin >> str;
        Solution ob;
        ret = ob.rearrangeString(str);
        cout << checker(str, ret) << endl;
    }
    return 0;
}
// } Driver Code Ends