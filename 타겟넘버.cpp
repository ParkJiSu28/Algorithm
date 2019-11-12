#include <string>
#include<string.h>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
#include<queue>
int answer;
vector<int>s;


int solution(vector<int> numbers, int target) {
	queue<int>q;
	q.push(numbers[0]);
	q.push(-numbers[0]);
	int cnt = 1;
	while (!q.empty()) {
		if (q.size() >= pow(numbers.size(), 2)) {
			while (!q.empty()) {
				if (target == q.front())
					answer++;
				q.pop();
			}
			break;
		}
		int temp = q.front();
		q.pop();
		if (cnt <=  pow(numbers.size(), 2)) {
			int mo = cnt%numbers.size();
			int plus = temp + numbers[mo];
			int minus = temp - numbers[mo];
			q.push(plus);
			q.push(minus);
		}
		cnt++;
	}
	
	return answer;
}


int main() {
	for (int i = 0; i < 3; i++) {
		int tem;
		cin >> tem;
		s.push_back(tem);
	}
	cout<<solution(s, 1);
}