//^ https://leetcode.com/problems/compare-version-numbers/

#include <string>
using namespace std;

class Solution
{
public:
    void checkZero(string &version, int &i)
    {
        while (i < version.size() && version[i] == '0')
            i++;
    }

    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0;
        checkZero(version1, i);
        checkZero(version2, j);

        while (i < version1.size() || j < version2.size())
        {
            int num1 = 0, num2 = 0;
            // Extract each revision number from version1
            while (i < version1.size() && version1[i] != '.')
            {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            // Extract each revision number from version2
            while (j < version2.size() && version2[j] != '.')
            {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            if (num1 < num2)
                return -1; // version1 is smaller
            else if (num1 > num2)
                return 1; // version1 is larger
            i++;          // Move to next character after dot
            j++;          // Move to next character after dot
        }
        return 0; // Both versions are equal
    }
};
