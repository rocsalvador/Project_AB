#include <iostream>
#include <chrono>
#include "task1.h"
#include "task2.h"
#include "task4.h"
#include "task5.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Task 1, 4 and 5:" << endl;
        cout << "./project [1,4,5]" << endl << endl;

        cout << "Task 2:" << endl;
        cout << "./project 2 [error_percentage] [id]" << endl;
        cout << "id -> 0 to only allow missmatches" << endl;
        cout << "   -> 1 to allow insertions and deletions" << endl;
        return 1;
    }

    int task = stoi(argv[1]);
    if (task == 2 and argc < 4) {
        cout << "Task 2:" << endl;
        cout << "./project 2 [error_percentage] [id]" << endl;
        cout << "id -> 0 to only allow missmatches" << endl;
        cout << "   -> 1 to allow insertions and deletions" << endl;
        return 1;   
    }
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
        break;
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
