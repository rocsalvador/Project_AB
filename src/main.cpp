#include <iostream>
#include <chrono>
#include "task1.h"
#include "task2.h"
#include "task4.h"
#include "task5.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Usage:" << endl;
        cout << "./project task_num < path/to/input" << endl;
        return 1;
    }
    int task = stoi(argv[1]);
    cout << "Task " << task << endl;
    cout << "---------------" << endl;

    auto t1 = chrono::high_resolution_clock::now();
    switch (task)
    {
    case 1:
        Task_1 task_1;
        task_1.solve();
        break;
    case 2:
        if (argc < 4) {
            cout << "Usage:" << endl;
            cout << "./project 2 [percentage] [allow_insertions]  < path/to/input" << endl;
            return 1;
        }
        Task_2 task_2;
        task_2.solve(stof(argv[2]), stoi(argv[3]));
        break;
    case 4:
    {
        Task_4 task_4;
        task_4.solve();
        task_4.getLengthDistribution();
        break;
    }
    case 5:
    {
        Task_5 task_5;
        task_5.solve();
    }
    default:
        cout << "No valid task" << endl;
        return 1;
    }
    auto t2 = chrono::high_resolution_clock::now();
    double secondsElapsed = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() / 1000.0;
    cout << "---------------" << endl;
    cout << "Elapsed time: " << secondsElapsed  << "s" << endl;
}
