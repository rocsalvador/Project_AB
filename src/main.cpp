#include <iostream>
#include <chrono>
#include "task1.h"
#include "task2.h"
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
        if (argc < 3) {
            cout << "Usage:" << endl;
            cout << "./project 2 percentage < path/to/input" << endl;
            return 1;
        }
        Task_2 task_2;
        task_2.solve(stof(argv[2]));
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        cout << "No valid task" << endl;
        return 1;
    }
    auto t2 = chrono::high_resolution_clock::now();
    double secondsElapsed = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() / 1000.0;
    cout << "---------------" << endl;
    cout << "Elapsed time: " << secondsElapsed  << "s" << endl;
}
