#include<iostream>
#include<cstdlib>
using namespace std;


int partition(int *arr, int left, int right) {
	int i, pindex, pivot;
	pindex = left;
	pivot = arr[right]; //마지막 원소를 pivot으로
	for (i = left; i < right; i++) {
		if (arr[i] <= pivot) {
			swap(arr[pindex], arr[i]);
			pindex++;
		}
	}
	swap(arr[pindex], arr[right]);
	return pindex;
}

int quicksort(int *arr, int left, int right) {
	int index;
	if (left >= right) {
		return 0;
	}
	index = partition(arr, left, right);
	quicksort(arr, left, index - 1);
	quicksort(arr, index + 1, right);
}


int main() {
	int arr[10] = { 1,4,5,67,33,56,54,42,99,40 };
	quicksort(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}