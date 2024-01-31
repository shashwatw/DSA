// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-strings/problem/most-frequent-non-bad-word

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
string MostFrequent(string paragraph, vector<string> taboo);

// } Driver Code Ends
// User function Template for C++

string MostFrequent(string p, vector<string> taboo)
{
    // Your Code
    map<string, int> wfreq;
    map<string, int> bad_words;
    for (int i = 0; i < taboo.size(); i++)
    {
        bad_words[taboo[i]] = 1;
    }
    int freq = -1;
    string res;
    for (int i = 0; i < p.length(); i++)
    {
        string s = "";
        while (i < p.length() && isalpha(p[i]))
            s += tolower(p[i++]);
        if (s != "" && bad_words.find(s) == bad_words.end())
        {
            wfreq[s]++;
            if (freq < wfreq[s])
            {
                freq = wfreq[s];
                res = s;
            }
        }
    }

    return res;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        string paragraph;
        getline(cin, paragraph);
        int n;
        cin >> n;
        vector<string> taboo(n);
        for (int i = 0; i < n; ++i)
            cin >> taboo[i];
        cout << MostFrequent(paragraph, taboo) << endl;
    }

    return 0;
}
// } Driver Code Ends
