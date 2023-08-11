#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs)
    {
        std::string prefix;

        if (strs.empty())
        {
            return prefix;
        }

        auto smallest_string = std::min_element(strs.begin(), strs.end(), [](auto& lhs, auto& rhs)
            {
                if (lhs.size() < rhs.size())
                    return true;
                return false;
            });

        prefix.reserve(smallest_string->size());

        for (size_t i = 0; i < smallest_string->size(); ++i)
        {
            char ch = smallest_string->at(i);
            bool allof = std::all_of(strs.begin(), strs.end(), [ch, i](auto& s)
                { return s[i] == ch; });

            if (!allof)
            {
                return prefix;
            }

            prefix.push_back(ch);
        }

        return prefix;
    }
};

int main()
{
    Solution s;

    std::cout << s.longestCommonPrefix(std::vector<std::string> { "cir", "car" }) << std::endl;
}