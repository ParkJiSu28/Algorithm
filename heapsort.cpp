#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	//left child가 root보다 클때

	if (l<n && arr[l]>arr[largest]) {
		largest = l;
	}
	//right child가 지금까지 최대값보다 큰경우

	if (r<n && arr[r]>arr[largest]) {
		largest = r;
	}
	//지금까지 최댓값이 root가 아닌경우
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapsort(int arr[], int n) {
	//Build Heap

	for (int i = (n / 2) - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
	//힙에서 하나의 원소  추출하기
	for (int i = n - 1; i >= 0; i--) {
		// 현재root를 끝으로 보내기
		swap(arr[0], arr[i]);
		// 하나 줄은 heap다시 heapify하기
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << "  ";
	cout << "\n";
}

int main() {
	int arr[] = { 12,7,9,5,4,2,1,4,6,8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	heapsort(arr, n);
	cout << "Sorted Array is \n";
	printArray(arr, n);
}
