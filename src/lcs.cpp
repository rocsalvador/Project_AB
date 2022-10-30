#include "lcs.h"
#include <bits/stdc++.h>

LCSuffix::LCSuffix(std::vector<char> alphabet) {
    counts = std::vector<std::vector<int>>();
    this->alphabet = alphabet;
    idMap = std::unordered_map<char, int>();
    charMap = std::unordered_map<int, char>();

    for (uint i = 0; i < alphabet.size(); i++) {
        idMap.insert({this->alphabet[i], i});
        charMap.insert({i, this->alphabet[i]});
    }
}

void LCSuffix::updateCount(std::string sequence) {
    char chars[sequence.length() + 1];
    strcpy(chars, sequence.c_str());

    for (uint i = 0; i < sequence.length() + 1; i++) {
        if (counts.size() < i + 1) 
            counts.push_back(std::vector<int>(alphabet.size()));
        char c = chars[(sequence.length()) - i];

        counts[i][idMap[c]] += 1;
    }
}

void LCSuffix::updateCount(std::vector<std::string> sequences) {
    for (std::string sequence : sequences)
        updateCount(sequence);
}

char LCSuffix::getCharWithMoreOcc(int index) {
    int hc = 0, hi = 0;
    std::vector<int> thisIndex = counts[index];

    for (uint i = 0; i < thisIndex.size(); i++) {
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

    for (uint i = 0; i < res.size(); i++)
        res[i] = getCharWithMoreOcc(i);
    
    std::stringstream ss;
    for (int i = res.size() - 1; i >= 0; i--)
        ss.put(res[i]);

    return ss.str();
}

std::string LCSuffix::multi_lcs(std::vector<std::string> sequences) {
    // Size of the array
    uint n = sequences.size();

    std::string s = sequences[0];
    uint l = s.length();
    std::string res = "";

    for (uint i = 0; i < l; i++) {
        for (uint j = i + 1; j < l + 1; j++) {
            // Generating all possible substrings of our reference string s
            std::string stem = s.substr(i, j-i);
            uint k;
            for (k = 1; k < n; k++) {
                // Checking if the generated stem is common to all words
                if (sequences[k].find(stem) == std::string::npos)
					break;
            } 
			// If current substring is present in all strings and it's length
            // is greater than current result
            if (k == n && res.length() < stem.length())
                res = stem;
        }
    }
    return res;
}