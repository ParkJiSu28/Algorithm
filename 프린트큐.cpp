#include<iostream>
#include<deque>
#include<algorithm>
#include<string.h>
using namespace std;


int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		int n, m;
		cin >> n >> m;
		deque<pair<int, int>>dq;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			if (i == m) {
				dq.push_back(make_pair(temp, m));

			}
			else
				dq.push_back(make_pair(temp, -1));
		}
		int ans=0;
		while (!dq.empty()) {
			int important = dq.front().first;//중요도
			int want = dq.front().second;//원하는 문서
			bool swaped = false;
			dq.pop_front();
			for (int i = 0; i < dq.size(); i++) {
				if (important < dq[i].first) {
					dq.push_back(make_pair(important,want));
					swaped = true;
					break;
				}
			}
			if (!swaped) {
				if (want == m) {
					ans += 1;
					cout << ans << endl;
					break;
				}
				else {
					ans += 1;
				}
			}

		}
	}
}