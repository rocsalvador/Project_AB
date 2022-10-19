#include "suffixtree.h"
#include <iostream>
#include <functional>
#include <string>

SuffixTree::SuffixTree(const std::string& s) {
    nodes.push_back(Node{});
    for (size_t i = 0; i < s.length(); i++) {
        addSuffix(s.substr(i));
    }
}

void SuffixTree::addSuffix(const std::string& suff) {
    int n = 0;
    size_t i = 0;
    while (i < suff.length()) {
        char b = suff[i];
        uint x2 = 0;
        uint n2;
        while (true) {
            auto children = nodes[n].childs;
            if (x2 == children.size()) {
                // no matching child -> reminder is a new node
                n2 = nodes.size();
                nodes.push_back(Node(suff.substr(i), {}));
                nodes[n].childs.push_back(n2);
                return;
            }
            n2 = children[x2];
            if (nodes[n2].sub[0] == b) {
                break;
            }
            x2++;
        }
        // find prefix of remaning suffix in common with child
        std::string sub2 = nodes[n2].sub;
        size_t j = 0;
        while (j < sub2.size()) {
            if (suff[i+j] != sub2[j]) {
                // split n2
                int n3 = n2;
                // new node for the part in common
                n2 = nodes.size();
                nodes.push_back(Node(sub2.substr(0,j), {n3}));
                nodes[n3].sub = sub2.substr(j); // old node loses the part in common
                nodes[n].childs[x2] = n2;
                break;  // continue
            }
            j++;
        }
        i += j;
        n = n2;
    }
}

void SuffixTree::showTree() {
    if (nodes.size() == 0) {
        std::cout << "\n";
        return;
    }
    std::function<void(int, const std::string&)> f;
    f = [&](int n, const std::string& pre) {
        auto children = nodes[n].childs;
        if (children.size() == 0) {
            std::cout << "- " << nodes[n].sub << '\n';
            return;
        }
        std::cout << "+ " << nodes[n].sub << '\n';

        auto it = std::begin(children);
        if (it != std::end(children)) do {
            if (std::next(it) == std::end(children)) break;
            std::cout << pre << "+-";
            f(*it, pre + "| ");
            it = std::next(it);
        } while (true);

        std::cout << pre << "+-";
        f(children[children.size() - 1], pre + " ");
    };

    f(0, "");
}
