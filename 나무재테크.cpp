#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, k;

struct TREE {
	int y, x, age;
};

bool cmp(TREE &a,TREE &b){
	
	return (a.age < b.age);
}
void clear_queue(queue<TREE>&anything) {
	queue<TREE>empty;
	swap(anything, empty);
}

queue<TREE> tree[2];
queue<TREE> new_tree;
queue<TREE>death_tree;
queue<TREE>birth_of_child;
TREE init_tree[100];
int map[10][10];
int add[10][10];
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };

void survival_tree(int k) {
	
	int next = 0;
	int cur = 0;
	for (int i = 0; i < m; i++) {
		tree[cur].push(init_tree[i]);
	}
	while (k--) {
		next = (cur + 1) % 2;
		clear_queue(new_tree);
		clear_queue(death_tree);
		clear_queue(tree[next]);
		//봄
		while (!new_tree.empty()) {//새로생긴 나무만 처리하는 while문
			TREE cur_tree = new_tree.front(); new_tree.pop();
			if (map[cur_tree.y][cur_tree.x] >= cur_tree.age) {
				map[cur_tree.y][cur_tree.x] -= cur_tree.age;
				cur_tree.age++;
				tree[next].push(cur_tree);
			}
			else {
				death_tree.push(cur_tree);
			}
		}
		while (!tree[cur].empty()) {
			TREE cur_tree = tree[cur].front(); tree[cur].pop();
			if (map[cur_tree.y][cur_tree.x] >= cur_tree.age) {
				map[cur_tree.y][cur_tree.x] -= cur_tree.age;
				cur_tree.age++;
				tree[next].push(cur_tree);
				if ((cur_tree.age % 5) == 0) {
					birth_of_child.push(cur_tree);
				}
			}
			else {
				death_tree.push(cur_tree);
			}
		}
		//여름
		while (!death_tree.empty()) {
			TREE cur_tree = death_tree.front(); death_tree.pop();
			map[cur_tree.y][cur_tree.x] += (cur_tree.age / 2);
		}
		//가을
		while (!birth_of_child.empty()) {
			TREE cur_tree = birth_of_child.front(); birth_of_child.pop();
			for (int dir = 0; dir < 8; dir++) {
				TREE next_tree;
				next_tree.y = cur_tree.y + dy[dir];
				next_tree.x= cur_tree.x + dx[dir];
				next_tree.age = 1;
				if (next_tree.x < n &&next_tree.x >= 0 && next_tree.y < n &&next_tree.y >= 0) {
					new_tree.push(next_tree);
				}
				
			}
		}
		//겨울
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				map[y][x] += add[y][x];
			}
		}
		cur = next;
	}
	cout << tree[next].size() + new_tree.size();
}

int main() {
	cin >> n >> m >> k;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> add[y][x];
			map[y][x] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> init_tree[i].y >> init_tree[i].x >> init_tree[i].age;
		init_tree[i].y--, init_tree[i].x--;
	}
	sort(init_tree, init_tree + m, cmp);
	
	survival_tree(k);
	return  0;
}
