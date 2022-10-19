#ifndef SUFFIXTREE_HH
#define SUFFIXTREE_HH

#include <string>
#include <vector>

class SuffixTree {
    public:
        struct Node {
            std::string sub = "";
            std::vector<int> childs;

            Node() {}

            Node(const std::string& sub, std::initializer_list<int> ch) : sub(sub) {
                childs.insert(childs.end(), ch);
            }
        };

        std::vector<Node> nodes;

        SuffixTree(const std::string& s);

        void showTree();

    private:
        void addSuffix(const std::string& suff);
};
#endif
