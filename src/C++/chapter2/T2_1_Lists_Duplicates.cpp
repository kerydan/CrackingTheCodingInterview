/*
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/
#include <string>
#include <unordered_set>
#include <list>

using namespace std;

list<int> solution_N(const list<int>& L){
 
    unordered_set<int> s;
    list<int> res = L;
    for (auto it = res.begin(); it != res.end(); ){
        if (s.count(*it)==0){
            s.insert(*it);
            it++;
        }
        else{
            auto it1 = it;
            it++;
            it = res.erase(it);
        }
    }
    return res;
}

list<int> solution_N2(const list<int>& L){

    unordered_set<int> s;
    list<int> res = L;
    auto it_last = --(res.end());
    auto it = res.begin();
    bool it_increased = false;
    do{
        it_increased = false;
        int cur = *it;
        auto run = ++it;
        while (run != res.end()){
            if (*run != cur){
                if (!it_increased){
                    it = run;
                    it_increased = true;
                }
                run++;
            }
            else{
                run = res.erase(run);
            }
        }
    } while (it_increased);
    return res;
}

