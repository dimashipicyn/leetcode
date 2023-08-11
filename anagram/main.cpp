#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    Solution()
        : symbols {}
    {
    }

    bool isAnagram(const std::string& s, const std::string& t)
    {
        for (char ch : s)
        {
            ++symbols[index(ch)];
        }

        for (char ch : t)
        {
            int& counter = symbols[index(ch)];
            if (counter != 0)
            {
                if (counter-- <= 0)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return !std::any_of(symbols.begin(), symbols.end(), [](int num) {
            return num > 0;
        });
    }

private:
    int index(char ch)
    {
        return ch - '0';
    }

    std::array<int, 70> symbols;
};

int main()
{
    Solution s;

    std::cout << s.isAnagram("anagram", "nagaram") << std::endl;
}