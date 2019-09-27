#include<iostream>
#include<string>
using namespace std;

int main() {
	string original;
	string bomb;
	getline(cin,original);
	getline(cin, bomb);
	string temp = original;
	
	while (temp.find(bomb) != string::npos || temp.empty()) {
		int idx = temp.find(bomb);
		if (temp.length() <= bomb.length()) {
			cout << "FRULA" << endl;
			return 0;
		}
		temp.erase(idx, bomb.length());
	}
	if (temp.empty())cout << "FRULA" << endl;
	else cout << temp << endl;
}