// Give a number, convert that to text. 123 as One hundred and twenty three.
// 1. std solution would be
//    std::string s = std::to_string(123);
// 2. Non-std solution: 
#include <string>

std::string GetText(int n, int dec) {
	std::string str;
	if (dec == 0 || dec == 2) {
		switch (n) {
		case 1: str = "one";
			break;
		case 2: str = "two";
			break;
		case 3: str = "three";
			break;
		case 4: str = "four";
			break;
		}
	}
	else if (dec == 1) {
		switch (n) {
		case 2: str = "twenty";
			break;
		case 3: str = "thirty";
			break;
		case 4: str = "fourty";
			break;
		}

	}
	else if (dec == -1) {
		switch (n) {
		case 2: str = "twelve";
			break;
		case 3: str = "thirteen";
			break;
		case 4: str = "fourteen";
			break;
		}

	}

	return str;
}

std::string Num2Text(int num){
	std::string str;
	
	int n = num;

	n= num/100;
	n %= 10;
	str = GetText(n,2);
	str += " hundred and ";
	n = num / 10;
	n %= 10;
	if (n != 1)
	{
		str += GetText(n, 1);
		str += " ";
		n = num;
		n %= 10;
		str += GetText(n, 0);
	}
	else
	{
		n = num;
		n %= 10;
		str += GetText(n, -1);	
	}




	return str;
}
