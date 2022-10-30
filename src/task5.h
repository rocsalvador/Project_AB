#ifndef TASK_5_HH
#define TASK_5_HH

#include <vector>
#include <string>
#include <tuple>

class Task_5 {
public:
    int BARCODE_LENGTH = 6;

    std::vector<std::string> fileLines;

    void init();

    void removeBarcodes(std::vector<std::string> sequences);

    std::pair<std::vector<std::string>, std::vector<std::string>> identifyBarcodes(std::vector<std::string> sequences);

    void numOfSeqPerSample(std::vector<std::string> barcodes);

    std::vector<int> seqLengthDist(std::vector<std::string> sequences, std::string barcode);

    std::vector<std::string> insertionsPerBarcode(std::vector<std::string> sequences, std::string barcode);

    void solve();
};

#endif