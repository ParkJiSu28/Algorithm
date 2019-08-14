#include<iostream>
#include<algorithm>
using namespace std;
int dwarf[9];



int main() {
	int t=0;
	int totalsum = 0;
	while (t!=9) {
		cin >> dwarf[t];
		totalsum += dwarf[t];
		t++;
	}
	bool check = false;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (totalsum - dwarf[i] - dwarf[j] == 100) {
				dwarf[i] = -1;
				dwarf[j] = -1;
				check = true;
				break;
			}
		}
		if (check)break;
	}
	sort(dwarf, dwarf + 9);
	for (int i = 2; i < 9; i++) {
		cout << dwarf[i]<<endl;
	}
	return 0;
}