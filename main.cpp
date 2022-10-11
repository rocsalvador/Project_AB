#include <iostream>
#include "task-1.h"
using namespace std;

int main() {
    int task;
    cout << "Input task to solve [1-5]: ";
    cin >> task;
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