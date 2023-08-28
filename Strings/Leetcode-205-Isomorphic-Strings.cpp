//https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, char> mapping;
        unordered_map<char, bool> usedChars;

        for (int i = 0; i < s.length(); i++) {
            char charS = s[i];
            char charT = t[i];

            if (mapping.find(charS) == mapping.end()) {
                if (usedChars.find(charT) != usedChars.end() && usedChars[charT]) {
                    return false; // charT is already mapped to another character
                }
                mapping[charS] = charT;
                usedChars[charT] = true;
            } else {
                if (mapping[charS] != charT) {
                    return false; // mapping is inconsistent
                }
            }
        }

        return true;
    }
};