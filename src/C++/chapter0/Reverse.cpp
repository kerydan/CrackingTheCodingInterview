// 1. Reverse a string without using a built-in function
// 2. Reverse a linked list without using a built-in function
// 3. Use standard function to reverse vector
// 4. Implement unit test checking correctness of N1 Reverse(string) implementation

#include <string>
#include <list>
#include <vector>

// N1
std::string ReverseString(const std::string& str) {
	std::string res = str;
	
	for (int i = 0; i < str.size()/2; i++) {
		res[i] = str[str.size() - 1 - i];
		res[str.size() - 1 - i] = str[i];
	}
	return res;
}

// N2
void ReverseList1(std::list<int>& l) {
	std::list<int> res;
	
	for(auto i : l) {
		res.push_front(i);
	}
	l = res;
}

// N3
void ReverseVector(std::vector<int>& v) {
	std::reverse(v.begin(), v.end());
}

// N4
bool ReverseLinkTest(std::list<int>& e) {
	std::list<int> etl = e;
	std::reverse(etl.begin(), etl.end());
	std::list<int> comp = e;
	ReverseList1(comp);
	return (comp == etl);
}