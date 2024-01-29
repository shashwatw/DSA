// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-strings/problem/print-anagrams-together
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        // Create a hash map to store anagrams
        unordered_map<string, vector<string>> anagramMap;

        // Iterate through the strings in the vector
        for (const string &str : string_list)
        {
            // Sort the string to get a unique representation for anagrams
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            // Add the string to the corresponding anagram group in the map
            anagramMap[sortedStr].push_back(str);
        }

        // Collect anagrams from the map
        vector<vector<string>> result;
        for (auto &pair : anagramMap)
        {
            result.push_back(pair.second);
        }

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}

// } Driver Code Ends