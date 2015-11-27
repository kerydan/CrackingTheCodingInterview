/*
Write a method to decide if two strings are anagrams or not.

*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


bool isAnagram_N_LogN(string S1, string S2){

    sort(S1.begin(), S1.end());
    sort(S2.begin(), S2.end());
    return S1==S2;
}

bool isAnagram_N(string S1, string S2){

    vector<int> letters(26, 0);
    int k = 'a';
    for (auto s : S1){
        letters[s - 0x61]++;
    }
    for (auto s : S2){
        letters[s - 0x61]--;
    }
    for (auto a : letters){
        if (a != 0)
            return false;
    }
    return true;
}


int main(){

    bool b1 = isAnagram_N_LogN("listen", "silnet");
    bool b2 = isAnagram_N_LogN("listen", "sionet");

    bool b3 = isAnagram_N("listen", "silnet");
    bool b4 = isAnagram_N("listen", "sionet");

    bool b5 = isAnagram_N("listen", "lniest");
    bool b6 = isAnagram_N("listen", "tsilne");

    bool b7 = isAnagram_N("listen", "tsilnek");
    bool b8 = isAnagram_N("listen", "ttsilne");


    int k = 0;
}

