//* https://leetcode.com/problems/fraction-addition-and-subtraction/

class Solution
{
public:
    string fractionAddition(string expression)
    {
        stringstream ss(expression);
        int numerator = 0, denominator = 1;
        char sign = '+';
        int num, denom;
        char slash;

        while (ss >> num >> slash >> denom)
        {
            if (sign == '-')
                num = -num;
            numerator = numerator * denom + num * denominator;
            denominator *= denom;
            int gcd = std::gcd(abs(numerator), denominator);
            numerator /= gcd;
            denominator /= gcd;
            ss >> sign;
        }

        return to_string(numerator) + '/' + to_string(denominator);
    }
};
