#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[8];
vector<int>v;                    

//void print_arr(int size) {
//	for (int i = 0; i < size; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//
//void permutation(int n, int r, int depth) {
//	if (r == depth) {
//		print_arr(depth);
//		return;
//	}
//	for (int i = depth; i < n; i++) {
//		swap(arr[i],arr[depth]);
//		permutation(n, r, depth + 1);
//		swap(arr[i], arr[depth]);
//	}
//}




int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		v.push_back(i+1);
	}
	cout << "next" << endl;
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	while (next_permutation(v.begin(), v.end())) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	v.clear();
	int num = n;
	for (int i = 0; i < n; i++) {
		v.push_back(num--);
	}
	cout << "prev" << endl;

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	while (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	v.clear();
	cout << "Combination 5c3" << endl;
	vector<int>temp;
	for (int i = 0; i < n; i++) {
		v.push_back(i + 1);
	}
	for (int i = 0; i < 3; i++) {
		temp.push_back(1);
	}
	for (int i = 0; i < v.size() - 3; i++) {
		temp.push_back(0);
	}
	sort(temp.begin(), temp.end());
	do {
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 1) {
				cout << v[i] << " ";
			}
		}
		cout << endl;
	} while (next_permutation(temp.begin(), temp.end()));

	return 0;
}