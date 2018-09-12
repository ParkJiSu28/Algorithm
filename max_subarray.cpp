using namespace std;
#include<iostream>
#include<limits.h>

int find_max_crossing_subarray(int a[], int low, int mid, int high) {
	int sum = 0;
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	
	for (int i = mid; i >=0 ; i--) {
		sum = sum + a[i];
		if (sum > left_sum) {
			left_sum = sum;
			
		}
	}
	sum = 0;
	for (int i = mid + 1; i <= high; i++) {
		sum = sum + a[i];
		if (sum > right_sum) {
			right_sum = sum;
		}
	}
	int total = left_sum + right_sum;
	return total;
}

int find_maximum_subarray(int a[], int low, int high) {
	int mid;
	int left_sum, right_sum,cross_sum;
	if (high == low)
		return a[low];

	else {
		mid = (low + high) / 2;
		left_sum = find_maximum_subarray(a, low, mid);
		right_sum = find_maximum_subarray(a, mid + 1, high);
		cross_sum = find_max_crossing_subarray(a, low, mid, high);
		if ((left_sum >= right_sum) && (left_sum >= cross_sum))
			return left_sum;
		else if ((right_sum >= left_sum) && (right_sum >= cross_sum))
			return right_sum;
		else
			return cross_sum;
	}
}


int main() {
	int a[] = { 1,4,9,-7,-8,13,-9};
	int n = sizeof(a) / sizeof(a[0]);
	printf("maximum subarray °ªÀº = %d", find_maximum_subarray(a, 0, n-1));
}

