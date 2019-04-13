#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m,answer;
struct POSITION {
	int y, x;
};

vector<POSITION>house, pick, shop;


void dfs(int v) {
	int candi = 0;
	if (pick.size() == m) {
		for (int i = 0; i < house.size(); i++) {
			int min_dist = 1000000;
			for (int j = 0; j < pick.size(); j++) {
							min_dist = min(min_dist,
					abs(house[i].y - pick[j].y) + abs(house[i].x - pick[j].x));
			}
			candi += min_dist;
		}if (answer > candi) {
			answer = candi;
		}
		return;
	}
	
	for (int i = v; i <shop.size(); i++) {
		pick.push_back(shop[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}

int main() {
	cin >> n >> m;
	int type;
	POSITION target;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> type;
			if (type == 1) {
				target.x = x;
				target.y = y;
				house.push_back(target);
			}
			if (type == 2) {
				target.x = x;
				target.y = y;
				shop.push_back(target);
			}
		}
	}
	answer = 0xfffffff;
	dfs(0);
	cout << answer << endl;
	return 0;
}