cmake_minimum_required(VERSION 3.20)

project(Leetcode)

#set(CMAKE_C_COMPILER "clang")
#set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#add_compile_options("/fsanitize=address")
#add_link_options("/fsanitize=address")

add_subdirectory(palindrome)
add_subdirectory(roman_numbers)
add_subdirectory(longest_prefix)
add_subdirectory(valid_parenthesis)
add_subdirectory(letter_combinations)