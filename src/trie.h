#include <vector>
#include <string>
#include <iostream>

class Trie {
private:
    struct Node {
        bool isWordEnd;
        bool isLeaf;
        std::vector<Node*> childs = std::vector<Node*>(4);
    };

    Node* root;

    int nuclToInt(char nucleotide);

public:
    Trie();

    ~Trie();

    void addText(const std::string& s, Node* node);

    uint longestPerfectMatch(const std::string& s);

    Node* getRoot();

    void show(Node* node);
};