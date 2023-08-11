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
    int reverse(int x)
    {
        int sign = 1;
        if (x < 0)
        {
            sign = -1;
            x *= -1;
        }

        long long result = 0;
        while (x > 0)
        {
            result *= 10;
            result += (x % 10);
            x /= 10;
        }

        return clamp(result * sign);
    }

private:
    int clamp(long long result)
    {
        if (result < std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max())
        {
            return 0;
        }

        return static_cast<int>(result);
    }
};

int main()
{
    Solution s;

    std::cout << s.reverse(1534236469) << std::endl;
}