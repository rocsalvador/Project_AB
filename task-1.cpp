#include <string>
#include <fstream>
#include "task-1.h"
#include "suffixtree.h"
#include <iostream>
using namespace std;

void Task_1::solve() {
    ifstream file("s_3_sequence_1M.txt");
    string s, a = "TGGAATTCTCGGGTGCCAAGGAACTCCAGTCACACAGTGATCTCGTATGCCGTCTTCTGCTTG";
    SuffixTree suffixTree;
    while (file >> s) {
        suffixTree.addSequence(s, suffixTree.getRoot());
    }
}