#include <vector>
#include <string>
#include <iostream>

class Trie {
private:
    struct Node {
        bool isLeaf;
        std::vector<Node*> childs = std::vector<Node*>(4);
    };

    Node* root;

    int nuclToInt(char nucleotide);

public:
    Trie();

    ~Trie();

    void addText(const std::string& s, Node* node);

    bool paritialMatch(const std::string& s, uint& depth, Node* node);

    bool partialMatchWithMissmatch(const std::string& s, uint& depth, int errors, int maxErrors, Node* node);

    Node* getRoot();

    void show(Node* node);
};