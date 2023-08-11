#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        if (nums.size() <= 1)
        {
            return {};
        }
        std::vector<int> result;
        result.reserve(nums.size());

        int num = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            num *= nums[i];
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            result.emplace_back(num / nums[i]);
        }

        return result;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums { 1, 2, 3, 4 };
    auto result = s.productExceptSelf(nums);
    std::cout << result[0] << std::endl;
    std::cout << result[1] << std::endl;
    std::cout << result[2] << std::endl;
    std::cout << result[3] << std::endl;
}