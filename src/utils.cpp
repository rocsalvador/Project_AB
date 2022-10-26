#include "utils.h"

std::string Utils::reverseString(const std::string& s) {
    std::string reversedString = "";
    for (int i = s.size() - 1; i >= 0; --i) reversedString.push_back(s[i]);
    return reversedString;
}