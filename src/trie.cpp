#include "trie.h"

Trie::Trie() {
    root = new Node;
}

void Trie::addText(const std::string& s, Node* node) {
    if (s != "") {
        auto result = node->childs.find(s[0]);
        std::string nextStr;
        Node* nextNode;
        if (s.length() == 1) nextStr = "";
        else nextStr = s.substr(1, s.length() - 1);
        if (result == node->childs.end()) {
            nextNode = new Node;
            node->childs.insert({s[0], nextNode});
        }
        else nextNode = result->second;
        addText(nextStr, nextNode);
    }
    else {
        node->childs.insert({'.', new Node});
    }
}

Trie::Node* Trie::getRoot() {
    return root;
}

bool Trie::search(const std::string& s, Node* node) {
    if (s == "") {
        if (node->childs.find('.') != node->childs.end()) return true;
        else return false;
    }
    else {
        auto result = node->childs.find(s[0]);
        std::string nextStr;
        if (s.length() == 1) nextStr = "";
        else nextStr = s.substr(1, s.length() - 1);
        if (result == node->childs.end()) return false;
        else return search(nextStr, result->second);
    }
}

bool Trie::searchWithMissmatch(const std::string& s, int errors, int maxErrors, Node* node) {
    if (s == "") {
        if (node->childs.find('.') != node->childs.end()) return true;
        else return false;
    }
    else {
        auto result = node->childs.find(s[0]);
        std::string nextStr;
        if (s.length() == 1) nextStr = "";
        else nextStr = s.substr(1, s.length() - 1);
        if (result == node->childs.end()) {
            if (errors <= maxErrors) {
                ++errors;
                return searchWithMissmatch(nextStr, errors, maxErrors, node);
            }
            else return false;
        }
        else return searchWithMissmatch(nextStr, errors, maxErrors, result->second);
    }
}
