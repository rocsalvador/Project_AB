#include <string>
#include <vector>

class Utils {
public:
    static std::string reverseString(const std::string& s);
    std::vector<std::string> findAndRemoveSuffixPrefixMatch(std::string a, std::vector<std::string> s, 
            int error, bool allowInDel);

    std::vector<std::string> findAndRemoveSuffixPrefixMatch(std::string a, std::vector<std::string> s);

    std::string createRandomDNAString(int len);

    void compare(std::string e, std::string a);
};