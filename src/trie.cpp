#include "trie.h"

Trie::Trie() {
    root = new Node;
    root->isWordEnd = false;
    root->isLeaf = true;
}

Trie::~Trie() {

}

int Trie::nuclToInt(char nucleotide) {
    if (nucleotide == 'A') return 0;
    else if (nucleotide == 'C') return 1;
    else if (nucleotide == 'G') return 2;
    else return 3;
}

void Trie::addText(const std::string& s, Node* node) {
    if (s != "") {
        int index = nuclToInt(s[0]);
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
    int index = nuclToInt(nextStr[0]);
    while (node->childs[index] != nullptr) {
        node = node->childs[index];
        ++remainder;
        if (nextStr.length() == 1) nextStr = "";
        else {
            nextStr = nextStr.substr(1, nextStr.length() - 1);
            index = nuclToInt(nextStr[0]);
        }
        if (node->isWordEnd) {
            longestMatch += remainder;
            remainder = 0;
        }

        if (node->isLeaf or nextStr == "") return longestMatch;
    }
    return longestMatch;
}
void Trie::show(Node* node) {

}