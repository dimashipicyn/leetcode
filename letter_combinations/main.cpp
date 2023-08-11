#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::string> letterCombinations(const std::string& digits)
    {
        const char* alphas[5] = { nullptr };
        int count = 0;
        for (char ch : digits)
        {
            alphas[count++] = alphabet[index(ch)];
        }

        std::vector<std::string> combinations;
        combinations.reserve(std::pow(digits.size(), digits.size()));

        std::string acc;
        acc.reserve(digits.size());

        get_combinations(combinations, acc, alphas);

        return combinations;
    }

private:
    void get_combinations(std::vector<std::string>& v, std::string& s, const char** alphas)
    {
        const char* a = *alphas;
        if (!a)
        {
            if (!s.empty())
            {
                v.emplace_back(s);
            }
            return;
        }

        for (; *a != '\0'; ++a)
        {
            s.push_back(*a);
            get_combinations(v, s, alphas + 1);
            s.pop_back();
        }
    }

    int index(char c)
    {
        return c - '0';
    }

    std::array<const char*, 10> alphabet = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
};

int main()
{
    Solution s;

    auto res = s.letterCombinations("234");
    for (auto& s : res)
    {
        std::cout << s << std::endl;
    }
}