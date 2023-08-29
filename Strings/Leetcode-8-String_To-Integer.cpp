//https://leetcode.com/problems/string-to-integer-atoi/description/


class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long result = 0;
        
        // Remove leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        
        // Check for optional sign
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }
        
        // Process digits
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');
            
            // Check for overflow or underflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
        }
        
        return result * sign;
    }
};
