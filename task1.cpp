#include <vector>
#include <iostream>
#include <functional>
#include <fstream>

struct Node {
    public:
        std::string sub = "";   // a substring of the input string
        std::vector<int> childs;    // vector of child nodes

        Node() {}

        Node(const std::string& sub, std::initializer_list<int> ch) : sub(sub) {
            childs.insert(childs.end(), ch);
        }
};

struct SuffixTree {
    public:
        std::vector<Node> nodes;

        SuffixTree(const std::string& s) {
            nodes.push_back(Node{});
            for (size_t i = 0; i < s.length(); i++) {
                addSuffix(s.substr(i));
            }
        }

        void showTree() {
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

    private:
        void addSuffix(const std::string& suff) {
            int n = 0;
            size_t i = 0;
            while (i < suff.length()) {
                char b = suff[i];
                int x2 = 0;
                int n2;
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
                auto sub2 = nodes[n2].sub;
                size_t j = 0;
                while (j < sub2.size()) {
                    if (suff[i+j] != sub2[j]) {
                        // split n2
                        auto n3 = n2;
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
};

int main() {
    std::ifstream file("s_3_sequence_1M.txt");
    std::string s, a = "TGGAATTCTCGGGTGCCAAGGAACTCCAGTCACACAGTGATCTCGTATGCCGTCTTCTGCTTG";
    int n = 0;
    while (file >> s and n < 1) {
        SuffixTree(s).showTree();
        n += 1;
    }
}