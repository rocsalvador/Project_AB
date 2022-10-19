#include <string>
#include <fstream>
#include "task1.h"
#include "suffixtree.h"
#include <iostream>
using namespace std;

void Task_1::solve() {
    std::ifstream file("data/s_3_sequence_1M.txt");
    std::string s, a = "TGGAATTCTCGGGTGCCAAGGAACTCCAGTCACACAGTGATCTCGTATGCCGTCTTCTGCTTG";
    int n = 0;
    while (file >> s) {
        SuffixTree suffixTree(s);
        ++n;
    }
}
