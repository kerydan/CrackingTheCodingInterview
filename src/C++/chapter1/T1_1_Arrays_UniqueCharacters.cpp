/*
You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100

*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


// TODO implement

int solution(vector<int> &A) {
    int rightSum = accumulate(A.begin(), A.end(), 0)-A[0];
    int leftSum = A[0];
    int minDiff = abs(rightSum - leftSum);
    for (auto i = 1; i + 1 < A.size(); i++){
        leftSum += A[i];
        rightSum -= A[i];
        int diff = abs(rightSum - leftSum);
        minDiff = diff < minDiff ? diff : minDiff;
    }
    return minDiff;
}

int main()
{
    vector<int> A{ 3, 1, 2, 4, 3 };
    int minDiff = solution(A);
    cout << "min difference is " << minDiff << endl;

	return 0;
}


