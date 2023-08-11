#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution
{
public:
    int myAtoi(const std::string& s)
    {
        std::string_view sv = s;

        int sign = 1;

        if (size_t first = sv.find_first_not_of(" \t"); first != std::string_view::npos)
        {
            sv.remove_prefix(first);
            if (size_t last = sv.find_first_not_of("-+0123456789"); last != std::string_view::npos)
            {
                sv.remove_suffix(sv.size() - last);
            }
        }
        
        if (sv.front() == '-')
        {
            sv.remove_prefix(1);
            sign = -1;
        }
        else if (sv.front() == '+')
        {
            sv.remove_prefix(1);
        }

        if (size_t first = sv.find_first_not_of("0 \t"); true)
        {
            first = (first != std::string_view::npos) ? first : sv.size();
            sv.remove_prefix(first);
        }

        if (sv.size() > 10)
        {
            return sign == 1 ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
        }

        long result = 0;
        for (char ch : sv)
        {
            if (!isdigit(ch))
            {
                return clamp(result * sign);
            }
            result *= 10;
            result = result + (ch - '0');
        }

        return clamp(result * sign);
    }

private:
    int clamp(long result)
    {
        return static_cast<int>(std::clamp<long>(result, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()));
    }
};

int main()
{
    Solution s;

    std::cout << s.myAtoi("123") << std::endl;
    std::cout << s.myAtoi("    0000000000000   ") << std::endl;
    std::cout << s.myAtoi("-20000000000000000001") << std::endl;
}