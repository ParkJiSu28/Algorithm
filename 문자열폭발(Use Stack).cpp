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
			if (front.top() == bomb[temp] && front.size() >=temp) { //���øǵڶ� ���� ���ڿ��̶� ���� ���� ���ڿ��� ��ź���ڿ����� ũ�ų� ������ 
				ended.push(front.top()); //end���ÿ� �ű��
				front.pop();
				temp -= 1;//�ܾ��� �ε����� �ϳ� ������Ű��
				suc += 1; //�ű�Ƚ���� ������Ų��.

				if (temp == -1 && ended.size() == len2) { //�ܾ� �ε����� ���� ���Ǿ��� �ű� ���ÿ� ����� ���߹��ڿ��� ���̿� ���ٸ�
					while (!ended.empty()) {
						ended.pop(); //�ű�� ���� �ӽ� ���� �ʱ�ȭ
					}
					temp = len2 - 1;//�ٽ� �ε����� ó������ �����ش�.

				}
			}
			else {
				while (suc != 0 && !ended.empty()) { //�ű�Ƚ���� 0�̾ƴϰ� �ӽý����� �Ⱥ������ 
					front.push(ended.top());// ���߹��ڿ��� �ƴѰ���̱� ������ ������������ �ٽ� push
					ended.pop();
					suc--;//�ű�Ƚ���� �ʱ�ȭ ���ش�.
				}
				temp = len2 - 1;
				break;
			}
		}
		while (!ended.empty()){ // ���� ��쿡�� ó������ ���� ���� �ӽý��ÿ� �ִٸ� �ٽ� ������������ push
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

