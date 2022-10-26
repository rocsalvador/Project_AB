#include <vector>
#include <string>
#include <unordered_map>

class LCSuffix {
private:
    std::vector<std::vector<int>> counts;
    std::vector<char> alphabet;
    std::unordered_map<char, int> idMap;
    std::unordered_map<int, char> charMap;

    char getMostLikely(int index);

public:
    LCSuffix(std::vector<char> alphabet);

    void process(std::string sequence);

    void process(std::vector<std::string> sequences);

    std::string getMostCommon();

};