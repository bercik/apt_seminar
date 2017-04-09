#include "gtest/gtest.h"

#include <iostream>
#include <algorithm>

std::string reverseString(const std::string& str)
{
    std::string reversed_str(str);
    std::reverse(reversed_str.begin(), reversed_str.end());

    return reversed_str;
}

bool isPalindrome(const std::string& str)
{
    return (str == reverseString(str));
}

TEST(IsPalindromeTest, Should_ReturnTrue_ForPalindrome)
{
    EXPECT_TRUE(isPalindrome("mom"));
    EXPECT_TRUE(isPalindrome("asddsa"));
    EXPECT_TRUE(isPalindrome("racecar"));
}

TEST(IsPalindromeTest, Should_ReturnFalse_ForNotPalindrome)
{
    EXPECT_FALSE(isPalindrome("mos"));
    EXPECT_FALSE(isPalindrome("safsagasagshgas"));
    EXPECT_FALSE(isPalindrome("dsahfash"));
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
