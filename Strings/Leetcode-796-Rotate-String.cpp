//https://leetcode.com/problems/rotate-string/description/

class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.length() != goal.length())
        {
            return false;
        }

        char first;
        for(int i =0 ; i< s.size(); i++)
        {
            first = s[0];
            s.erase(0,1);
            s += first;

            if(s == goal)
            {
                return true;
            }
        }
        return false;
    }
};