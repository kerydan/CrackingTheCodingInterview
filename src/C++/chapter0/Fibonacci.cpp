// 1. Write a Fibonacci function using recursion
// 2. Write a Fibonacci function using iteration
// 3. Write a unit test to check above implemented Fibonacci functions


#include <iostream>
using namespace std;

int FibRec(int i) {
	if (i < 2) {
		return i;
	}
	return (FibRec(i - 2) + FibRec(i - 1));
}

int FibIt(int i) {
	if (i == 0) {
		return 0;
	}
	int old = 0;
	int cur = 1;
	for (int k = 2; k < i; k++) {
		int tmp = cur;
		cur = old + cur;
		old = tmp;
	}
	return (old + cur);
}


bool FibTest() {

	int et[] = { 0,1,1,2,3,5,8,13,21 };

	//unit test
	bool passed = true;
	for (int i = 0; i < sizeof(et) / sizeof(int); i++) {
		if (FibRec(i) != et[i] || FibIt(i) != et[i]) {
			cout << "FAILED. i=" << i << endl;

			cout << " Recursive: expected=" << et[i] << ", actual=" << FibRec(i) << endl << "----------------------------" << endl;
			cout << " Itterative: expected=" << et[i] << ", actual=" << FibIt(i) << endl << "----------------------------" << endl;
			passed = false;
			break;
		}
	}
	if (passed) {
		cout << "PASSED." << endl;
		return true;
	}
	return false;
}
