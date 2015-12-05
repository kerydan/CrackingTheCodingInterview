/*
       Implement a solution to the dining philosophers problem.The solution should be non - blocking and dead - lock free.

*/


#include "stdafx.h"
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <memory>

using namespace std;


class Fork
{
public:
    Fork(){};
    Fork(int ind) : ind{ ind }{};
    mutex m;
    int ind;
};

void Act(Fork* leftFork, Fork* rightFork, int philosopherNumber)
{

    int res = 0;
    do{
        res = try_lock(leftFork->m, rightFork->m);
        if (res == -1) {
            lock_guard<mutex> a(leftFork->m, adopt_lock);
            lock_guard<mutex> b(rightFork->m, adopt_lock);

            string s = "Philosopher " + to_string(philosopherNumber) + " picked " + to_string(leftFork->ind) + " fork and " + to_string(rightFork->ind) + " fork.\n";
            cout << s;
            s = "Philosopher " + to_string(philosopherNumber) + " eats\n";
            this_thread::sleep_for(chrono::milliseconds(50));
            cout << s;
        }
        else{
            string s = "Philosopher " + to_string(philosopherNumber) + " thinks\n";
            cout << s;
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    } while (res != -1);
};




int main()
{
    static const int PHIL_MAX = 5;
    vector< unique_ptr<Fork> > fork(PHIL_MAX);

    for (int i = 0; i < PHIL_MAX; ++i){
        auto f = unique_ptr<Fork>(new Fork(i));
        fork[i] = move(f);
    }

    vector<thread> phil(PHIL_MAX);
    for (int i = 0; i < PHIL_MAX; ++i){
        phil[i] = (thread(Act, fork[i == 0 ? PHIL_MAX - 1 : i - 1].get(), fork[i].get(), i));
    }

    for (auto& t : phil){
        t.join();
    }

    return 0;
}




