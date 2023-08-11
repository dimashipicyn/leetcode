#include <iostream>
#include <string>


class Solution {
public:
	bool isPalindrome(int x) {
		std::string pal = std::to_string(x);

		auto begin = pal.begin();
		auto end = pal.end();

		while (begin < end)
		{
			if (*begin != *(--end))
			{
				return false;
			}
			++begin;
		}

		return true;
	}
};

int main()
{
	Solution s;

	std::cout << s.isPalindrome(11) << std::endl;
}