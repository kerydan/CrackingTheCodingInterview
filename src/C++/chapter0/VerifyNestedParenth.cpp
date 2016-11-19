// Write Verify(text) function, checking if parentheses within text are correctly nested
#include <string>
#include <iostream>

using namespace std;

bool VerifyParenth(const string& str) {

	int par = 0;
	for (auto i : str) {
		if (i == '{') {
			par--;
		}
		else if (i == '}') {
			par++;
		}
		if (par > 0)
			return false;
	}

	return (par == 0);

}

bool ParUnitTest() {
	bool res = true;
	if (!VerifyParenth("")
		|| !VerifyParenth("0 {1} ")
		|| !VerifyParenth("0 {1{}}{} ")
		|| VerifyParenth("0 {{1{}}{} ")
		|| VerifyParenth("0 {1{}}{}}{ ")
		)
	{
		res = false;
	}
	if(!res)
	{
		cout << "TEST FAILED";
		return false;
	}
	else
	{
		cout << "TEST PASSED";
		return true;
	}

}