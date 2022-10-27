#include "task4.h"
#include "lcs.h"
#include "utils.h"
#include "trie.h"

#include <string>
#include <iostream>
#include <fstream>

void Task_4::init() {
    std::string s;

    /*unknown-adapter.txt*/
    std::ifstream file1("data/tdt4287-unknown-adapter.txt");
    while (std::getline(file1, s)) {
        S.push_back(s);
    }
    /*s_3_sewquence.txt*/
    std::ifstream file2("data/s_3_sequence_1M.txt");
    while (std::getline(file2, s)) {
        controlS.push_back(s);
    }
    /*seqset3.txt*/
    std::ifstream file3("data/seqset3.txt");
    while (std::getline(file3, s)) {
        S2.push_back(s);
    }
}

void Task_4::solve() {
    init();

    std::cout << "1: Randomly guessing the adapter" << std::endl;
    Utils::compare(controlA, Utils::createRandomDNAString(controlA.length()));

    std::cout << std::endl;

    std::cout << "2: Testing algorithm for sequence with known adapter" << std::endl;
    LCSuffix control = LCSuffix(alphabet);
    control.process(controlS);
    std::string controlRes = control.getMostCommon();
    Utils::compare(controlA, controlRes);

    std::cout << std::endl;

    std::cout << "3: Finding sequence in 'seqset3.txt'" << std::endl;
    LCSuffix lcSuffix = LCSuffix(alphabet);
    lcSuffix.process(S2);
    B = lcSuffix.getMostCommon();
    std::cout << "Sequence found: " << B << std::endl;

    std::cout << std::endl;

    std::cout << "4: Finding most likely adapter in 'tdt4287-unknown-adapter.txt'" << std::endl;
    lcSuffix = LCSuffix(alphabet);
    lcSuffix.process(S);
    A = lcSuffix.getMostCommon();
    std::cout << "Most likely adapter sequence: " << A << std::endl;

    std::cout << std::endl;
}

void Task_4::getLengthDistribution() {

    std::cout << "5: Finding sequences with match and length distribution" << std::endl;

    std::string s;
    std::vector<uint> lengthDistribution = std::vector<uint> (A.size());
    std::string reversedA = Utils::reverseString(A);
    Trie trie;
    for (uint i = 0; i < reversedA.size(); ++i) {
        trie.addText(reversedA.substr(i, reversedA.size() - i), trie.getRoot());
    }
    uint matches = 0, totalS = 0, maxSize = 0;
    for (std::string s : S) {
        maxSize = std::max(uint(s.size()), maxSize);
        std::string reversedS = Utils::reverseString(s);
        uint length = trie.longestPerfectMatch(reversedS);
        if (length != 0) ++matches;
        uint remainingLength = s.size() - length;
        ++lengthDistribution[remainingLength];
        ++totalS;
    }
    std::cout << "Sequences with a match: " << matches << " (" << matches / float(totalS) * 100 << "%)" << std::endl;
    std::cout << "Length distribution:" << std::endl;
    for (uint i = 0; i <= maxSize; ++i) std::cout << i << ": " << lengthDistribution[i] << std::endl;;
}