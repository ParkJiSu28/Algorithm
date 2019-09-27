#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
string croatia[] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

int main() {
	string word;
	getline(cin,word);
	int len = word.length();
	if (len == 2) {
		for (int i = 0; i < 8; i++) {
			if (word.find(croatia[i]) != string::npos) {
				len = 1;
				cout << 1;
				return 0;
			}
		}
	}
	cout << len << endl;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == 'c' || word[i] == 'd' || word[i] == 'l' || word[i] == 'n' || word[i] == 's' || word[i] == 'z') {
			if (word[i] == 'c'&&(word[i+1] =='=' ||word[i+1]=='-')&&i<word.length()-1){
				len -=1;
			}
			else if (word[i] == 's' && (word[i + 1] == '=') && i < word.length() - 1) {
				len -= 1;

			}
			else if (word[i] == 'z' && (word[i + 1] == '=') && i < word.length() - 1) {
				len -= 1;
				
			}
			else if (word[i] == 'd' && (word[i + 1] == '-') && i < word.length() - 1) {
				len -= 1;
				
			}
			else if (word[i] == 'd' && (word[i + 1] == 'z') && word[i + 2] == '=' && i < word.length() - 2) {
				len -= 2;
				
				i = i + 2;
			}
			else if (word[i] == 'n' && (word[i + 1] == 'j') && i < word.length() - 1) {
				len -= 1;
			}
			else if (word[i] == 'l' && (word[i + 1] == 'j') && i < word.length() - 1) {
				len -= 1;
			}
		}
	}
	cout << len << endl;
}
