#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	//left child�� root���� Ŭ��

	if (l<n && arr[l]>arr[largest]) {
		largest = l;
	}
	//right child�� ���ݱ��� �ִ밪���� ū���

	if (r<n && arr[r]>arr[largest]) {
		largest = r;
	}
	//���ݱ��� �ִ��� root�� �ƴѰ��
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
	//������ �ϳ��� ����  �����ϱ�
	for (int i = n - 1; i >= 0; i--) {
		// ����root�� ������ ������
		swap(arr[0], arr[i]);
		// �ϳ� ���� heap�ٽ� heapify�ϱ�
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
