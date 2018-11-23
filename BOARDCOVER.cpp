#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;
vector <vector<int>> board;

const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{ { 0,0 },{ 1,0 },{ 1,-1 } }
};

bool set(vector<vector<int>>&board, int y, int x, int type,int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size()) {
			ok = false;
		}
		else if ((board[ny][nx] += delta) > 1) {
			ok = false;
		}
	}
	return ok;
}

int cover(vector<vector<int>>&board) {
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)break;
	}
	//�������
	int ret = 0;
	for (int type = 0; type < 4; ++type) {
		//���� �� �ִٸ�
		if (set(board, y, x, type, 1)) {
			ret += cover(board);
		}
		//���ٸ�
		set(board, y, x, type, -1);
	}
	return ret;
}

int main() {
	int test;
	cin >> test;
	for (int i = 0; i < test; i++) {
		int n, m;
		cin >> n>>m;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					char l;
					cin >> l;
					board.push_back(vector <int>());
					if (l == '#') {
						board[i].push_back(1);
					}
					else {
						board[i].push_back(0);
					}
				}

			}
			cout << cover(board)<< endl;
	}
	return 0;
}


/*
���� �� �ִ� L�Ǹ���� �װ����� ������ 
������ ������ �������� �ǿ������� ������ ��������
���� �ٸ� ���ȣ��� �ߺ��� �����ϸ�ī��Ʈ
*/