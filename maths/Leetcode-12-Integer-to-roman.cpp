// https://leetcode.com/problems/integer-to-roman/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {

        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<std::string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";
        int index = 0;

        while (num > 0)
        {
            while (num >= values[index])
            {
                result += symbols[index];
                num -= values[index];
            }
            index++;
        }

        return result;
    }
};