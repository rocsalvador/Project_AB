#include <string>
#include <vector>

class Utils {
public:
    static std::string reverseString(const std::string& s);

    std::vector<std::string> findAndRemoveSuffixPrefixMatch(std::string a, std::vector<std::string> s, int error, bool allowInDel);

    std::vector<std::string> findAndRemoveSuffixPrefixMatch(std::string a, std::vector<std::string> s);

    std::string createRandomDNAString(int len);

    static uint editDistance(const std::string& a, const std::string& s);

    static uint nuclToInt(char nucleotide);

    static char intToNucl(uint i);

    void compare(std::string e, std::string a);
};