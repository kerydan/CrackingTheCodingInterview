/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100

*/

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int solution(int N, int M, int i, int j) {
    int mask = (1 << (j-i)) - 1; // 1's for 4 rightmost bit, all leftmost bits set to 0
    mask <<= i;         // 0's before position j, them 1's , 0's after position i
    mask = ~mask;       // inverted mask
    int res = N & mask; // clear position between i and j
    mask = M << i;
    res |= mask;        // copy M into N between positions i and j
    return res;
}


int main(){

    int k1 = solution(strtol("10000000000", NULL, 2), strtol("10101", NULL, 2), 2, 6);
    cout << "k1 = " << bitset<32>(k1) << endl;

    int k = 0;
}


