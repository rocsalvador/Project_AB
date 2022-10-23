#include <string>
#include "task2.h"
#include "trie.h"
#include <iostream>
using namespace std;

void Task_2::solve(float percentage) {
    std::string s, a = "TGGAATTCTCGGGTGCCAAGGAACTCCAGTCACACAGTGATCTCGTATGCCGTCTTCTGCTTG";
    Trie trie;
    for (uint i = 1; i <= a.size(); ++i) {
        trie.addText(a.substr(0, i), trie.getRoot());
    }
    uint lengthDistr = 0, n = 0;
    while (cin >> s) {
        for (uint i = s.size(); i > 0; --i) {
            int maxErrors = i * (percentage / 100.0);
            if (trie.searchWithMissmatch(s.substr(s.size() - i, i), 0, maxErrors, trie.getRoot())) {
                // cout << s.substr(s.size() - i, i) << endl;
                lengthDistr += s.size() - s.substr(s.size() - i, i).size();
                ++n;
                break;
            }
        }
    }
    lengthDistr /= n;
    cout << "Sequences with a match: " << n << endl;
    cout << "Length distribution: " << lengthDistr << endl;
}
