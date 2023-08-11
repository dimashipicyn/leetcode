#include <iostream>
#include <string>

class Solution
{
public:
    int romanToInt(std::string s)
    {
        int number = 0;
        char prev = '\0';
        for (char ch : s)
        {
            switch (ch)
            {
            case 'I':
            {
                ++number;
                break;
            }
            case 'V':
            {
                if (prev == 'I')
                {
                    number += 3;
                }
                else
                {
                    number += 5;
                }
                break;
            }
            case 'X':
            {
                if (prev == 'I')
                {
                    number += 8;
                }
                else
                {
                    number += 10;
                }
                break;
            }
            case 'L':
            {
                if (prev == 'X')
                {
                    number += 30;
                }
                else
                {
                    number += 50;
                }
                break;
            }
            case 'C':
            {
                if (prev == 'X')
                {
                    number += 80;
                }
                else
                {
                    number += 100;
                }
                break;
            }
            case 'D':
            {
                if (prev == 'C')
                {
                    number += 300;
                }
                else
                {
                    number += 500;
                }
                break;
            }
            case 'M':
            {
                if (prev == 'C')
                {
                    number += 800;
                }
                else
                {
                    number += 1000;
                }
                break;
            }
            default:
                break;
            }
            prev = ch;
        }

        return number;
    }
};

int main()
{
    Solution s;

    std::cout << s.romanToInt("I") << std::endl;
    std::cout << s.romanToInt("V") << std::endl;
    std::cout << s.romanToInt("X") << std::endl;
    std::cout << s.romanToInt("L") << std::endl;
    std::cout << s.romanToInt("C") << std::endl;
    std::cout << s.romanToInt("D") << std::endl;
    std::cout << s.romanToInt("M") << std::endl;
    std::cout << s.romanToInt("MCMXCIV") << std::endl;
}