#include <gtest/gtest.h>
#include "../lib_algorithms/Algorithms.h"

TEST(TestAlg, is_easy_correct)
{
    std::string ex = "(({[()]}))";
    bool expected = true;
    bool res = check_brackets(ex);
    EXPECT_EQ(res, expected);
}

TEST(TestAlg, is_null_correct)
{
    std::string ex = "";
    bool expected = true;
    bool res = check_brackets(ex);
    EXPECT_EQ(res, expected);
}

TEST(TestAlg, is_wrong_correct)
{
    std::string ex = "(({[(])}))";
    bool expected = false;
    bool res = check_brackets(ex);
    EXPECT_EQ(res, expected);
}

TEST(TestAlg, is_begin_wrong_correct)
{
    std::string ex = ")(({[()]}))";
    bool expected = false;
    bool res = check_brackets(ex);
    EXPECT_EQ(res, expected);
}

TEST(TestAlg, is_end_wrong_correct)
{
    std::string ex = "(({[()]}))[";
    bool expected = false;
    bool res = check_brackets(ex);
    EXPECT_EQ(res, expected);
}