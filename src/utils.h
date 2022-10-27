#include <string>
#include <vector>

class Utils {
public:
    static std::string reverseString(const std::string& s);

    static std::string createRandomDNAString(int len);

    static uint editDistance(const std::string& a, const std::string& s);

    static uint nuclToInt(char nucleotide);

    static char intToNucl(uint i);

    static void compare(std::string e, std::string a);
};