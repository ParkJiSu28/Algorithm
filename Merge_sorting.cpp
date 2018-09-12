#include <iostream>
#define ITEM_SIZE 10
using namespace std;

void print_arr(int a[], int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}


void merge(int a[], int left, int mid, int right) {
	int i, j, k;

	i = left;
	j = mid + 1;
	k = left;

	int tmp_arr[ITEM_SIZE];

	// left ���� mid ������ ��ϰ� mid + 1 ���� right ������ ����� ���� ��
	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) {
			tmp_arr[k] = a[i];
			i++;
		}
		else {
			tmp_arr[k] = a[j];
			j++;
		}
		k++;
	}

	// left ����� ���� �� ó���Ǿ�����, right ����� index�� ���� �ִ� ���
	// right ����� ���� �κ��� ���������� tmp_arr�� ����
	if (i > mid) {
		for (int m = j; m <= right; m++) {
			tmp_arr[k] = a[m];
			k++;
		}
	}
	// left ����� ���� �κ��� ���������� tmp_arr�� ����
	else {
		for (int m = i; m <= mid; m++) {
			tmp_arr[k] = a[m];
			k++;
		}
	}

	// �ӽ� �迭�� tmp_arr�� ���� ���� �迭�� �����Ѵ�.
	for (int m = left; m <= right; m++) {
		a[m] = tmp_arr[m];
	}
}

void merge_sort(int a[], int left, int right) {
	int mid;
	if (left < right) {
		//�߰�ã��
		mid = (left + right) / 2;

		//divide
		merge_sort(a, left, mid);
		merge_sort(a, mid + 1, right);

		//combine
		merge(a, left, mid, right);
	}
}



int main() {
	int a[ITEM_SIZE] = { 2,4,8,12,9,24,94,21,54,9};
	print_arr(a, ITEM_SIZE);
	merge_sort(a, 0, ITEM_SIZE - 1);
	print_arr(a, ITEM_SIZE);
	return 0 ;
}