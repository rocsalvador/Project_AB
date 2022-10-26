#include "trie.h"

Trie::Trie() {
    root = new Node;
    root->isLeaf = false;
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
            nextNode->isLeaf = true;
            node->childs[index] = nextNode;
        }
        else nextNode = node->childs[index];
        addText(nextStr, nextNode);
    }
    else node->isLeaf = true;
}

Trie::Node* Trie::getRoot() {
    return root;
}

bool Trie::paritialMatch(const std::string& s, uint& depth, Node* node) {
    if (node->isLeaf) return true;
    if (s == "") return node->isLeaf;
    else {
        int index = nuclToInt(s[0]);
        std::string nextStr;
        if (s.length() == 1) nextStr = "";
        else nextStr = s.substr(1, s.length() - 1);
        if (node->childs[index] == nullptr) return false;
        else return paritialMatch(nextStr, ++depth, node->childs[index]);
    }
}

bool Trie::partialMatchWithMissmatch(const std::string& s, uint& depth, int errors, int maxErrors, Node* node) {
    if (node->isLeaf) return true;
    if (s == "") return node->isLeaf;
    else {
        int index = nuclToInt(s[0]);
        std::string nextStr;
        if (s.length() == 1) nextStr = "";
        else nextStr = s.substr(1, s.length() - 1);
        if (node->childs[index] == nullptr) {
            if (errors < maxErrors) {
                ++errors;
                // Deletion
                if (partialMatchWithMissmatch(nextStr, ++depth, errors, maxErrors, node)) {
                    return true;
                }
                for (Node* child : node->childs) {
                    if (child != nullptr) {
                        // Addition
                        if (partialMatchWithMissmatch(s, ++depth, errors, maxErrors, child)) {
                            return true;
                        }
                        
                        // Missmatch
                        if (partialMatchWithMissmatch(nextStr, ++depth, errors, maxErrors, child)) {
                            return true;
                        }
                    }
                }
                return false;
            }
            else return false;
        }
        else return partialMatchWithMissmatch(nextStr, ++depth, errors, maxErrors, node->childs[index]);
    }
}

void Trie::show(Node* node) {

}