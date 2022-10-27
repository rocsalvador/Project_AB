#include "trie.h"
#include "utils.h"

Trie::Trie() {
    root = new Node;
    root->isWordEnd = false;
    root->isLeaf = true;
}

Trie::~Trie() {

}

void Trie::setPercentage(float percentage) {
    this->percentage = percentage;
}

void Trie::setMaxTotalErrors(uint maxTotalErrors) {
    this->maxTotalErrors = maxTotalErrors;
}

void Trie::addText(const std::string& s, Node* node) {
    if (s != "") {
        int index = Utils::nuclToInt(s[0]);
        std::string nextStr;
        Node* nextNode;
        if (s.length() == 1) nextStr = "";
        else nextStr = s.substr(1, s.length() - 1);
        node->isLeaf = false;
        if (node->childs[index] == nullptr) {
            nextNode = new Node;
            nextNode->isWordEnd = false;
            nextNode->isLeaf = true;
            node->childs[index] = nextNode;
        }
        else nextNode = node->childs[index];
        addText(nextStr, nextNode);
    }
    else node->isWordEnd = true;
}

Trie::Node* Trie::getRoot() {
    return root;
}

uint Trie::longestPerfectMatch(const std::string& s) {
    uint longestMatch = 0, remainder = 0;
    Node* node = root;
    std::string nextStr = s;
    int index = Utils::nuclToInt(nextStr[0]);
    while (node->childs[index] != nullptr) {
        node = node->childs[index];
        ++remainder;
        if (nextStr.length() == 1) nextStr = "";
        else {
            nextStr = nextStr.substr(1, nextStr.length() - 1);
            index = Utils::nuclToInt(nextStr[0]);
        }
        if (node->isWordEnd) {
            longestMatch += remainder;
            remainder = 0;
        }

        if (node->isLeaf or nextStr == "") return longestMatch;
    }
    return longestMatch;
}

uint Trie::longestImperfectMatch(const std::string& s, uint longest, uint length, uint errors, Node* node) {
    if (errors > maxTotalErrors) return longest;

    uint maxErrors = length * (percentage / 100.0);
    if (s == "") {
        if (node->isWordEnd and errors <= maxErrors) longest = std::max(length, longest);
        return longest;
    }
    uint index = Utils::nuclToInt(s[0]);
    std::string nextStr;
    if (nextStr.length() == 1) nextStr = "";
    else nextStr = s.substr(1, s.length() - 1);
    if (node->isWordEnd and errors <= maxErrors) longest = std::max(length, longest);
    ++length;
    for (uint i = 0; i < node->childs.size(); ++i) {
        Node* child = node->childs[i];
        if (child != nullptr) {
            if (i == index) longest = std::max(longest, longestImperfectMatch(nextStr, longest, length, errors, child));
            else longest = std::max(longest, longestImperfectMatch(nextStr, longest, length, errors  + 1, child));
        }
    }
    return longest;
}

uint Trie::longestImperfectMatchID(const std::string& s, const std::string& suf, const std::string& pref, uint longest, uint length, Node* node) {
    uint errors = Utils::editDistance(suf, pref);
    if (errors > maxTotalErrors) return longest;

    uint maxErrors = length * (percentage / 100.0);
    if (s == "") {
        if (node->isWordEnd and errors <= maxErrors) longest = std::max(length, longest);
        return longest;
    }
    uint index = Utils::nuclToInt(s[0]);
    std::string nextStr;
    if (nextStr.length() == 1) nextStr = "";
    else nextStr = s.substr(1, s.length() - 1);
    if (node->isWordEnd and errors <= maxErrors) longest = std::max(length, longest);
    ++length;
    std::string nextSuf = suf;
    nextSuf.push_back(s[0]);
    for (uint i = 0; i < node->childs.size(); ++i) {
        Node* child = node->childs[i];
        if (child != nullptr) {
            std::string nextPref = pref;
            nextPref.push_back(Utils::intToNucl(i));
            if (i == index) longest = std::max(longest, longestImperfectMatchID(nextStr, nextSuf, nextPref, longest, length, child));
            else longest = std::max(longest, longestImperfectMatchID(nextStr, nextSuf, nextPref, longest, length, child));
        }
    }
    return longest;
}


void Trie::show(Node* node) {

}