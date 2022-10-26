#ifndef TASK_4_HH
#define TASK_4_HH

#include <vector>
#include <string>
#include "utils.h"

class Task_4 {
public:
    const std::vector<char> alphabet = {'A' , 'C' , 'T' , 'G' , 'N'};

    std::vector<std::string> S;
    std::string A;

    std::vector<std::string> controlS;
    const std::string controlA = "TGGAATTCTCGGGTGCCAAGGAACTCCAGTCACACAGTGATCTCGTATGCCGTCTTCTGCTTG";
    std::vector<std::string> S2;

    Utils u;

    void init();

    void solve();
};

#endif