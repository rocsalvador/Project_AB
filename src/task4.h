#ifndef TASK_4_HH
#define TASK_4_HH

#include <vector>
#include <string>

class Task_4 {
public:
    const std::vector<char> alphabet = {'A' , 'C' , 'T' , 'G' , 'N'};

    std::vector<std::string> S;
    std::string A;
    std::string B;

    std::vector<std::string> controlS;
    const std::string controlA = "TGGAATTCTCGGGTGCCAAGGAACTCCAGTCACACAGTGATCTCGTATGCCGTCTTCTGCTTG";
    std::vector<std::string> S2;

    void init();

    void solve();

    void getLengthDistribution();

    void getFrequencyDistribution();
};

#endif