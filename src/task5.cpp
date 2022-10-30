#include "task5.h"
#include "lcs.h"
#include "enumerate.h"

#include <fstream>
#include <algorithm>    // std::copy
#include <iostream>

void Task_5::init() {
    std::string s;

    std::ifstream file("data/MultiplexedSamples.txt");
     while (std::getline(file, s)) {
        fileLines.push_back(s);
    }
}

void Task_5::removeBarcodes(std::vector<std::string> sequences) {
    for (std::string sequence : sequences)
        sequence = sequence.substr(0, sequence.length() - BARCODE_LENGTH);
}

std::pair<std::vector<std::string>, std::vector<std::string>> Task_5::identifyBarcodes(std::vector<std::string> sequences) {
     /* Part 1 - identify the
        barcodes (3’ adapters) used and thereby how many samples were multiplexed
     */

    // Find 3' adapter through most common subseq
    // Remove these and filter afterwards
    // The remaining suffix is now the barcodes
    std::vector<std::string> barcodes;

    // have to copy the lines
    // go through sequences
    // find lcs ( this will be adapt seq first )
    // remove lines with adapter completely from list we are iterating over Copy-seqs
    // remove lcs at end from the same lines we're removing entirely from the other list SEQS
    std::vector<std::string> copyOfSequences;
    for (uint i = 0; i < sequences.size(); i++) {
        copyOfSequences.push_back(sequences[i]);
    }

    // Seqs share same length

    while (true) {
        if (copyOfSequences.empty()) {
            for (std::string seq : sequences) {
                barcodes.push_back(seq.substr(-BARCODE_LENGTH, seq.length()));
                seq = seq.substr(0, seq.length() - BARCODE_LENGTH);
            }
            break;
        }
        std::string lcs = LCSuffix::multi_lcs(copyOfSequences);

        std::cout << "Done lcs: " << lcs << std::endl;

        if (lcs.empty())
            break;

        std::vector<int> indexesToPop;
        for (uint i = 0; i < copyOfSequences.size(); i++) {
            uint startIndex = copyOfSequences[i].find(lcs);
            if (startIndex != std::string::npos) {
                sequences[i] = copyOfSequences[i].substr(0, startIndex + 1);
                indexesToPop.push_back(i);
            }
        }
        std::cout << "Done indexesToPop" << std::endl;
        std::vector<int>::iterator it;
        uint sizeOfCopy = copyOfSequences.size();
        copyOfSequences.clear();
        for (uint i = 0; i < sizeOfCopy; i++) {
            it = std::find(indexesToPop.begin(), indexesToPop.end(), i);
            if (it != indexesToPop.end()) {
                copyOfSequences.push_back(sequences[i]);
            }
        }
        std::cout << "done copyOfsequences" << std::endl;
    }
    return std::make_pair(barcodes, sequences);
}

void Task_5::numOfSeqPerSample(std::vector<std::string> barcodes) {
    /*Part 2 - identify how many sequences that were sequenced from each sample.*/
    std::pair<int, std::string> res;
    for (uint i = 0; i < barcodes.size(); i++) {
        int freqOfBarcode = std::count(barcodes.begin(), barcodes.end(), barcodes[i]);
        res = std::make_pair(freqOfBarcode, barcodes[i]);
        std::cout << i << " Barcode: " << res.first << " " << res.second << std::endl;
    }
}

std::vector<int> Task_5::seqLengthDist(std::vector<std::string> sequences, std::string barcode) {
    /*Part 3 - identify the sequence length distribution within each sample.*/
    std::vector<int> lengthDist;

    for (std::string seq : sequences) {
        int l = seq.length();
        if (seq.substr(-BARCODE_LENGTH, seq.length()) == barcode)
            lengthDist.push_back(l - BARCODE_LENGTH);
    }
    return lengthDist;
}

std::vector<std::string> Task_5::insertionsPerBarcode(std::vector<std::string> sequences, std::string barcode) {
    std::vector<std::string> insertions;

    for (std::string seq : sequences) {
        int l = seq.length();
        std::string insertion = seq.substr(0, l - BARCODE_LENGTH);
        if (seq.substr(-BARCODE_LENGTH, seq.length()) == barcode)
            insertions.push_back(insertion);
    }
    return insertions;
}

void Task_5::solve() {
    init();

    std::cout << "Done initializing" << std::endl;

    std::cout << std::endl;

    std::pair<std::vector<std::string>, std::vector<std::string>> barcodesAndSeqs = identifyBarcodes(fileLines);

    std::cout << std::endl;

    std::cout << "Part 1:" << std::endl;
    std::cout << "We have " << barcodesAndSeqs.first.size() << " barcodes" << std::endl;
    std::cout << "This are the barcodes: " << std::endl;
    for (uint i = 0; i < barcodesAndSeqs.first.size(); i++) {
        std::cout << barcodesAndSeqs.first[i] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Part 2:" << std::endl;
    numOfSeqPerSample(barcodesAndSeqs.first);

    std::cout << std::endl;

    std::cout << "Part 3:" << std::endl;
    removeBarcodes(barcodesAndSeqs.second);
    
    for (std::string bc : barcodesAndSeqs.first) {
        std::vector<int> dist = seqLengthDist(barcodesAndSeqs.second, bc);
        
        std::cout << "Length Distribution:" << std::endl;
        for (uint i = 0; i < dist.size(); i++) {
            std::cout << dist[i] << std::endl;
        }

        std::vector<std::string> insertionsForBc = insertionsPerBarcode(barcodesAndSeqs.second, bc);
        std::string res;
        int freqOfBarcode = 0, actFreqOfBarcode;
        for (uint i = 0; i < insertionsForBc.size(); i++) {
            actFreqOfBarcode = std::count(insertionsForBc.begin(), insertionsForBc.end(), insertionsForBc[i]);
            if (actFreqOfBarcode > freqOfBarcode) {
                freqOfBarcode = actFreqOfBarcode;
                res = insertionsForBc[i];
            }
        }
        std::cout << "The most common barcode is: " << res << std::endl;
    }
}