#include <asserts.hpp>
#include <recursion.hpp>

void test_should_reverse_a_word()
{
    std::string word = "ABC";
    std::string expected ="CBA";

    std::string result = recursiveReverseWord(word);

    ASSERT_STREQ(expected, result);
}

void RUN_RECURSION_TEST_SUITE()
{
    test_should_reverse_a_word();
}
