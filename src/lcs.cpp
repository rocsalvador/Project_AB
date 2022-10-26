#include "lcs.h"
#include <bits/stdc++.h>

LCSuffix::LCSuffix(std::vector<char> alphabet) {
    counts = std::vector<std::vector<int>>();
    this->alphabet = alphabet;
    idMap = std::unordered_map<char, int>();
    charMap = std::unordered_map<int, char>();

    for (int i = 0; i < alphabet.size(); i++) {
        idMap.insert({this->alphabet[i], i});
        charMap.insert({i, this->alphabet[i]});
    }
}

void LCSuffix::process(std::string sequence) {
    char chars[sequence.length() + 1];
    strcpy(chars, sequence.c_str());

    for (int i = 0; i < sequence.length() + 1; i++) {
        if (counts.size() < i + 1) 
            counts.push_back(std::vector<int>(alphabet.size()));
        char c = chars[(sequence.length()) - i];

        counts[i][idMap[c]] += 1;
    }
}

void LCSuffix::process(std::vector<std::string> sequences) {
    for (std::string sequence : sequences)
        process(sequence);
}

char LCSuffix::getMostLikely(int index) {
    int hc = 0, hi = 0;
    std::vector<int> thisIndex = counts[index];

    for (int i = 0; i < thisIndex.size(); i++) {
        int count = thisIndex[i];
        if (hc < count) {
            hc = count;
            hi = i;
        }
    }
    return charMap[hi];
}

std::string LCSuffix::getMostCommon() {
    std::vector<char> res(counts.size());

    for (int i = 0; i < res.size(); i++)
        res[i] = getMostLikely(i);
    
    std::stringstream ss;
    for (int i = res.size() - 1; i >= 0; i--)
        ss.put(res[i]);

    return ss.str();
}