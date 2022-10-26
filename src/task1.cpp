#include "task1.h"
#include "utils.h"
#include "trie.h"
#include <iostream>
using namespace std;

void Task_1::solve() {
    std::string s, a = "TGGAATTCTCGGGTGCCAAGGAACTCCAGTCACACAGTGATCTCGTATGCCGTCTTCTGCTTG";
    std::vector<uint> lengthDistribution = std::vector<uint> (a.size());
    std::string reversedA = Utils::reverseString(a);
    Trie trie;
    for (uint i = 0; i < reversedA.size(); ++i) {
        trie.addText(reversedA.substr(i, reversedA.size() - i), trie.getRoot());
    }
    uint matches = 0, totalS = 0, maxSize = 0;
    while (cin >> s) {
        maxSize = max(uint(s.size()), maxSize);
        std::string reversedS = Utils::reverseString(s);
        uint depth = 0;
        if (trie.paritialMatch(reversedS, depth, trie.getRoot())) {
            uint remainingLength = s.size() - depth;
            ++lengthDistribution[remainingLength];
            ++matches;
        }
        ++totalS;
    }
    cout << "Sequences with a match: " << matches << " (" << matches / float(totalS) * 100 << "%)" << endl;
    cout << "Length distribution:" << endl;
    for (uint i = 0; i < maxSize; ++i) cout << i + 1 << ": " << lengthDistribution[i] << endl;;
}
