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

    float percentage;

    uint maxTotalErrors;

public:
    Trie();

    ~Trie();

    void setPercentage(float percentage);

    void setMaxTotalErrors(uint maxTotalErrors);

    void addText(const std::string& s, Node* node);

    uint longestPerfectMatch(const std::string& s);

    uint longestImperfectMatch(const std::string& s, uint longest, uint length, uint errors, Node* node);

    uint longestImperfectMatchID(const std::string& s, const std::string& suff, const std::string& pref, uint longest, uint length, Node* node);

    Node* getRoot();

    void show(Node* node);
};