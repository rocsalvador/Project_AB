#include "suffixtree.h"
#include <iostream>

SuffixTree::SuffixTree() {
    root = new Node;
}

SuffixTree::Node* SuffixTree::getRoot() {
    return root;
}

void SuffixTree::addSequence(string sequence, Node* node) {
    if (sequence != "") {
        auto result = node->childs.find(sequence[0]);
        Node* nextNode;
        if (result == node->childs.end())  {
            nextNode = new Node;
            node->childs.insert({sequence[0], nextNode});
        }
        else nextNode = result->second;

        if (sequence.size() == 1) sequence = "";
        else sequence = sequence.substr(0, sequence.size()-1);
        addSequence(sequence, nextNode);
    }
}