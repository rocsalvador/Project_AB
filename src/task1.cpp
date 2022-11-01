#include "task1.h"
#include "utils.h"
#include "trie.h"
#include <iostream>
#include <fstream>
using namespace std;

void Task_1::solve() {
    std::ifstream inputFile("data/s_3_sequence_1M.txt");
    std::string s, a = "TGGAATTCTCGGGTGCCAAGGAACTCCAGTCACACAGTGATCTCGTATGCCGTCTTCTGCTTG";
    std::vector<uint> lengthDistribution = std::vector<uint> (a.size());
    std::string reversedA = Utils::reverseString(a);
    Trie trie;
    for (uint i = 0; i < reversedA.size(); ++i) {
        trie.addText(reversedA.substr(i, reversedA.size() - i), trie.getRoot());
    }
    uint matches = 0, totalS = 0, maxSize = 0;
    while (inputFile >> s) {
        maxSize = max(uint(s.size()), maxSize);
        std::string reversedS = Utils::reverseString(s);
        uint length = trie.longestPerfectMatch(reversedS);
        if (length != 0) ++matches;
        uint remainingLength = s.size() - length;
        ++lengthDistribution[remainingLength];
        ++totalS;
    }
    cout << "Sequences with a match: " << matches << " (" << matches / float(totalS) * 100 << "%)" << endl;
    cout << "Length distribution:" << endl;
    for (uint i = 0; i <= maxSize; ++i) cout << i << ": " << lengthDistribution[i] << endl;;
}
