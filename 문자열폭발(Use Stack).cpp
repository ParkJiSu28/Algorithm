#include<iostream>
#include<string>
#include<string.h>
#include<stack>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
stack<char>front;
stack<char>ended;

int main() {
	string original;
	string bomb;
	getline(cin,original);
	getline(cin, bomb);
	int len = original.length();
	int len2 = bomb.length();
	int suc = 0;
	int temp = len2 - 1;
	for (int i = 0; i < len; i++) {
		front.push(original[i]);
		while (!front.empty()) {
			if (front.top() == bomb[temp] && front.size() >=temp) { //스택맨뒤랑 폭발 문자열이랑 같고 남은 문자열이 폭탄문자열보다 크거나 같을때 
				ended.push(front.top()); //end스택에 옮기고
				front.pop();
				temp -= 1;//단어의 인덱스를 하나 증가시키고
				suc += 1; //옮긴횟수를 증가시킨다.

				if (temp == -1 && ended.size() == len2) { //단어 인덱스가 전부 사용되었고 옮긴 스택에 사이즈가 폭발문자열의 길이와 같다면
					while (!ended.empty()) {
						ended.pop(); //옮기기 위한 임시 스택 초기화
					}
					temp = len2 - 1;//다시 인덱스를 처음으로 돌려준다.

				}
			}
			else {
				while (suc != 0 && !ended.empty()) { //옮긴횟수가 0이아니고 임시스택이 안비었으면 
					front.push(ended.top());// 폭발문자열이 아닌경우이기 때문에 원래스택으로 다시 push
					ended.pop();
					suc--;//옮긴횟수를 초기화 해준다.
				}
				temp = len2 - 1;
				break;
			}
		}
		while (!ended.empty()){ // 위의 경우에도 처리되지 못한 값이 임시스택에 있다면 다시 원래스택으로 push
			front.push(ended.top());
			ended.pop();
			temp = len2 - 1;
		}
	}
	if (front.empty()) {
		cout << "FRULA" << endl;
		return 0;
	}
	vector<char>ans;
	while (!front.empty()) {
		ans.push_back(front.top());
		front.pop();
	}
	reverse(ans.begin(),ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	cout << endl;
}

