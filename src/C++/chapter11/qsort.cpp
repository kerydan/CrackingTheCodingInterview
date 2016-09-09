//
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void quickSort(vector<int>& arr, int left = -1, int right = -1) {
	int i = left, j = right;
	if (-1 == left) {
		left = i = 0;
		right = j = arr.size()-1;
	}
	int pivot = arr[(left + right) / 2];

	/* partitioning */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int main()
{
	vector<int> A{ 1,3,2,5,5,6,1, 4};
	quickSort(A);

	return 0;
}