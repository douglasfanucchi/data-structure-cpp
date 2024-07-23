#include <recursion.hpp>

std::string recursiveReverseWord(const std::string &str) {
    if (str.length() == 0) {
        return "";
    }
    return recursiveReverseWord(str.substr(1)) + str.at(0);
}

std::string noRecursiveReverseWord(const std::string &str) {
    size_t top = str.length();
    char stack[top];
    std::string result("");

    for(int i = 0; i < top; i++)
        stack[i] = str.at(i);
    for(;top > 0;)
        result += stack[--top];
    return result;
}
