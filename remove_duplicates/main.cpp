#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        int prev = nums.front();
        auto predicate = [&prev](int num) {
            if (num == prev)
            {
                return true;
            }
            prev = num;
            return false;
        };
        nums.erase(std::remove_if(++nums.begin(), nums.end(), predicate), nums.end());
        return nums.size();
    }
};

int main()
{
    Solution s;
    std::vector<int> nums { 1, 1, 2, 3, 3, 4, 5 };
    std::cout << s.removeDuplicates(nums) << std::endl;
}