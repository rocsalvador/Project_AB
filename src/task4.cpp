#include "task4.h"
#include "lcs.h"

#include <string>
#include <iostream>
#include <fstream>

void Task_4::init() {
    std::string s;

    /*unknown-adapter.txt*/
    std::ifstream file1("data/tdt4287-unknown-adapter.txt");
    while (std::getline(file1, s)) {
        S.push_back(s);
    }
    /*s_3_sewquence.txt*/
    std::ifstream file2("data/s_3_sequence_1M.txt");
    while (std::getline(file2, s)) {
        controlS.push_back(s);
    }
    /*seqset3.txt*/
    std::ifstream file3("data/seqset3.txt");
    while (std::getline(file3, s)) {
        S2.push_back(s);
    }
}

void Task_4::solve() {
    init();

    std::cout << "1: Randomly guessing the adapter" << std::endl;
    u.compare(controlA, u.createRandomDNAString(controlA.length()));

    std::cout << "2: Testing algorithm for sequence with known adapter" << std::endl;
    LCSuffix control = LCSuffix(alphabet);
    control.process(controlS);
    std::string controlRes = control.getMostCommon();
    u.compare(controlA, controlRes);

    std::cout << "RESULT: Finding most likely adapter in 'tdt4287-unknown-adapter.txt'" << std::endl;
    LCSuffix lcSuffix = LCSuffix(alphabet);
    lcSuffix.process(S);
    A = lcSuffix.getMostCommon();
    std::cout << "Most likely adapter sequence: " << A << std::endl;

    std::cout << "4: Finding sequence in 'seqset3.txt'" << std::endl;
    lcSuffix = LCSuffix(alphabet);
    lcSuffix.process(S2);
    A = lcSuffix.getMostCommon();
    std::cout << "Sequence found: " << A << std::endl;
}