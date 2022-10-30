#include "utils.h"
#include "trie.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <random>
#include <algorithm> 

std::string Utils::randomDNAsequence(int len) {
    std::vector<char> alphabet = {'A', 'C', 'T', 'G'};
    
    std::stringstream ss;
    for (int i = 0; i < len; i++)
        ss.put(alphabet[rand() % alphabet.size() + 1]);
    
    return ss.str();
}

void Utils::compare(std::string e, std::string a) {
    std::cout << "Original: " << e << std::endl;
    std::cout << "Estimated: " << a << std::endl;

    int correct = 0;
    int compLen = std::min(e.length(), a.length());

    std::cout << "Similarity:" << std::endl;

    for (int i = 0; i < compLen; i++) {
        if (e[i] == a[i]) {
            std::cout << e[i];
            correct++;
        }
        else {
            std::cout << "-";
        }
    }
    std::cout << std::endl;
    double percentageCorrect = 100.0 * (double) correct / compLen;
    std::cout << "Match percentage of: " << percentageCorrect << std::endl;
}

std::string Utils::reverseString(const std::string& s) {
    std::string reversedString = "";
    for (int i = s.size() - 1; i >= 0; --i) reversedString.push_back(s[i]);
    return reversedString;
}

uint Utils::editDistance(const std::string& s, const std::string& a) {
    uint m = s.length() + 1, n = a.length() + 1;
    std::vector<std::vector<uint>> dp = std::vector<std::vector<uint>> (m, std::vector<uint> (n));
    for (uint i = 0; i < m; ++i) {
        for (uint j = 0; j < n; ++j) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (s[i - 1] == a[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
               dp[i][j] = 1 + std::min(dp[i][j - 1], std::min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[m - 1][n - 1];
} 

uint Utils::nuclToInt(char nucleotide) {
    if (nucleotide == 'A') return 0;
    else if (nucleotide == 'C') return 1;
    else if (nucleotide == 'G') return 2;
    else return 3;
}

char Utils::intToNucl(uint i) {
    if (i == 0) return 'A';
    else if (i == 1) return 'C';
    else if (i == 2) return 'G';
    else return 'T';
}