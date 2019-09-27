#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		string word = "";
		cin >> word;
		vector<char>group;
		char temp = word[0];
		group.push_back(word[0]);
		bool flag = false;
		for (int i = 1; i < word.length(); i++) {
			if (temp == word[i]) {
				continue;
			}
			else {
				for (int j = 0; j < group.size(); j++) {
					if (group[j] == word[i]) {
						flag = true;
						break;
					}
				}
				if (flag == false) {
					group.push_back(word[i]);
					temp = word[i];
				}
			}
			if (flag)break;
		}
		if (!flag) ans += 1;
	}
	cout << ans << endl;
}