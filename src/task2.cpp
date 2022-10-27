#include <string>
#include "task2.h"
#include "trie.h"
#include "utils.h"
#include <iostream>
using namespace std;

void Task_2::solve(float percentage, bool allowID) {
    std::string s, a = "TGGAATTCTCGGGTGCCAAGGAACTCCAGTCACACAGTGATCTCGTATGCCGTCTTCTGCTTG";
    std::vector<uint> lengthDistribution = std::vector<uint> (a.size());
    std::string reversedA = Utils::reverseString(a);
    Trie trie;
    trie.setPercentage(percentage);
    for (uint i = 0; i < reversedA.size(); ++i) {
        trie.addText(reversedA.substr(i, reversedA.size() - i), trie.getRoot());
    }
    uint lengthDistr = 0, matches = 0, totalS = 0, maxSize = 0;
    while (cin >> s) {
        ++totalS;
        if (totalS % 10000 == 0) cout << totalS << endl;
        maxSize = max(uint(s.size()), maxSize);
        std::string reversedS = Utils::reverseString(s);
        uint maxTotalErrors = s.size() * (percentage / 100.0);
        trie.setMaxTotalErrors(maxTotalErrors);
        uint length = 0;
        if (not allowID) length = trie.longestImperfectMatch(reversedS, 0, 0, 0, trie.getRoot());
        else {
            std::string pref = "", suf = "";
            length = trie.longestImperfectMatchID(reversedS, suf, pref, 0, 0, trie.getRoot());
        }
        if (length != 0) ++matches;
        uint remainingLength = s.size() - length;
        ++lengthDistribution[remainingLength];
    }
    lengthDistr /= matches;
    cout << "Sequences with a match: " << matches << " (" << matches / float(totalS) * 100 << "%)" << endl;
    cout << "Length distribution:" << endl;
    for (uint i = 0; i <= maxSize; ++i) cout << i << ": " << lengthDistribution[i] << endl;;
}
