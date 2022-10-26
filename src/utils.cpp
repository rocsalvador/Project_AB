#include "utils.h"
#include "trie.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <random>
#include <algorithm> 

/*FALTA FER SUFFIX TREE -> AGAFAR-LO DEL MEU PRIMER COMMIT*/
std::vector<std::string> Utils::findAndRemoveSuffixPrefixMatch(std::string a, std::vector<std::string> s, 
            int error, bool allowInDel) {
    
    std::vector<std::string> waf;
    /*
         * To find the sequences in S that have a suffix that perfectly match a prefix of the
         * adapter, i reverse both strings, that way i only need to create 1 suffixtree. (finding a
         * prefix in reversed "S" that matches the suffix in reverse "a")
    */ 
}

std::vector<std::string> Utils::findAndRemoveSuffixPrefixMatch(std::string a, std::vector<std::string> s) {
    return findAndRemoveSuffixPrefixMatch(a, s, 0, false);
}

std::string Utils::createRandomDNAString(int len) {
    std::vector<char> alphabet = {'A', 'C', 'T', 'G', 'N'};
    
    std::stringstream ss;
    for (int i = 0; i < len; i++)
        ss.put(alphabet[rand() % alphabet.size() + 1]);
    
    return ss.str();
}

void Utils::compare(std::string e, std::string a) {
    std::cout << "Expected: " << e << std::endl;
    std::cout << "Actual: " << a << std::endl;

    int correct = 0;
    int compLen = std::min(e.length(), a.length());

    std::cout << "Matching:" << std::endl;

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
    std::cout << "Correct: " << percentageCorrect << std::endl;
}

std::string Utils::reverseString(const std::string& s) {
    std::string reversedString = "";
    for (int i = s.size() - 1; i >= 0; --i) reversedString.push_back(s[i]);
    return reversedString;
}