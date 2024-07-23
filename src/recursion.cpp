#include <recursion.hpp>

std::string recursiveReverseWord(const std::string &str) {
    if (str.length() == 0) {
        return "";
    }
    return recursiveReverseWord(str.substr(1)) + str.at(0);
}
