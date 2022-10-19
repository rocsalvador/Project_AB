#include <iostream>
#include "task1.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Usage:" << endl;
        cout << "./project task_num" << endl;
        return 1;
    }
    int task = stoi(argv[1]);
    cout << "-----------------------------------" << endl;
    cout << "- Task " << task << "                          -" << endl;
    cout << "-----------------------------------" << endl;
    switch (task)
    {
    case 1:
        Task_1 solver;
        solver.solve();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        cout << "No valid task" << endl;
        return 1;
    }
}
