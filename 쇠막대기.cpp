#include <cstdio>
#include<iostream>
#include<string>
using namespace std;
#include<stack>
#include<algorithm>


int main() {
	string str;
	cin >> str;
	stack <int> s;
	int sum = 0;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			s.pop();
			if (str[i - 1] == '(' &&  i>=2) {
				sum = sum + s.size();
				cout << sum << endl;
			}
			else {
				sum++;
			}
		}
	}
	cout << sum;
}
