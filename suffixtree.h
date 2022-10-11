#ifndef SUFFIXTREE_HH
#define SUFFIXTREE_HH

#include <unordered_map>
#include <string>
using namespace std;

class SuffixTree {
private:
    struct Node {
        unordered_map<char, Node*> childs;
    };

    Node* root;

public:
    SuffixTree();

    Node* getRoot();

    void addSequence(string sequence, Node* node);

    void visualize(Node* node);
};

#endif
