// Given an unsorted array of integers and integer x, find all pairs of 
// integers from the array which sum is x.


#include <vector>
#include <set>


// 3, 4, 3, 4,     7  

int SumOfPair(std::vector<int>& v, int sum) {
	int res = 0;
	std::multiset<int> mm(v.begin(),v.end());
	for (auto i : v) {
		int n = sum - i;
		if (i == n) {
			if (mm.count(i) >= 2) {
				mm.erase(mm.find(i));
				mm.erase(mm.find(i));
				res++;
			}		
		}
		else {
			auto first = mm.find(i);
			auto sec = mm.find(n);
			if (first != mm.end() && sec != mm.end()) {
				mm.erase(first);
				mm.erase(sec);
				res++;
			}
		}

	}

	return res;
}

bool SumOfPair_UnitTest(){
	bool b = true;
	std::vector<int> v{1,2,3};
	int n = SumOfPair(v, 7);
	b &= (n == 0);
	v = { 4,4,4,4 };
	n = SumOfPair(v, 8);
	b &= (n == 2);
	v = { 4,4,3,4 };
	n = SumOfPair(v, 8);
	b &= (n == 1);
	v = { 3,12,3,4,11,5,6,11 };
	n = SumOfPair(v, 15);
	b &= (n == 2);





	return b;


}