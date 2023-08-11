#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

template <class T>
class Alloc : public std::allocator<T>
{
public:
    T* allocate(const size_t count)
    {

        T* result = bytes + used_count;
        used_count += count;
        return result;
    }

    void deallocate(T* const ptr, const size_t count)
    {
        used_count -= count;
    }

private:
    char bytes[128];
    int used_count = 0;
};

class Solution
{
public:
    bool isValid(const std::string& s)
    {
        char open_braces[] = { '(', '[', '{' };
        char close_braces[] = { ')', ']', '}' };

        std::stack<char, std::vector<char, Alloc<char>>> st;
        for (char ch : s)
        {
            auto end = open_braces + 3;
            if (std::find(open_braces, end, ch) != end)
            {
                st.push(ch);
            }
            else
            {
                size_t index = std::distance(close_braces, std::find(close_braces, close_braces + 3, ch));
                if (st.empty() || st.top() != open_braces[index])
                {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};

int main()
{
    Solution s;

    std::cout << s.isValid("()[]{}") << std::endl;
}