// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-strings/problem/anagram-of-string

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        cout << remAnagram(str1, str2);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(std::string S1, std::string S2)
{
    // Initialize arrays to store frequency of characters
    int countS1[26] = {0};
    int countS2[26] = {0};

    // Count frequency of characters in S1
    for (char c : S1)
    {
        countS1[c - 'a']++;
    }

    // Count frequency of characters in S2
    for (char c : S2)
    {
        countS2[c - 'a']++;
    }

    // Calculate the absolute difference in frequencies
    int deletions = 0;
    for (int i = 0; i < 26; i++)
    {
        deletions += std::abs(countS1[i] - countS2[i]);
    }

    return deletions;
}