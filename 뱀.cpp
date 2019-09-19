#include<iostream>
#include<string.h>
using namespace std;

int d[100][100];
bool apple[100][100];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };


int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	while (k--) {
		int x, y;
		cin >> x >>y;
		apple[x - 1][y - 1] = true;
	}
	memset(d, -1, sizeof(d));
	int x = 0;int y = 0;
	int dir = 0;
	int len = 1;
	d[x][y] = 0;
	int l;
	cin >> l;
	int now = 0;
	for (int k = 0; k <= l; k++) {
		int t = n*n*+1;
		char ch = 'L';
		cin >> t >> ch;
		while (now < t) {
			x = x + dx[dir];
			y = y + dy[dir];
			now += 1;
			//������ ����� �ð��� ����ϰ� �����Ѵ�.
			if (x < 0 || y < 0 || x > n - 1 || y > n - 1) {
				cout << now << endl;
				return 0;
			}//����� ������ ����� �԰� ĭ�� ����� ���� ���� �����̸� 1�ø���.
			if (apple[x][y]) {
				apple[x][y] = false;
				len += 1;
			}// �湮�� ���� �ְ� �ڱ��ڽ��Ǹ��� �浹�ϸ� �ð��� ����ϰ� �����Ѵ�.
			//now-d[x][y]== �湮�Ϸ��� �ϴ� ĭ�� ���ʿ� �湮���� �˼� �ִ°� d[x][y]�̰� �װ� ���� �ð����� ���� ���� ���̰� ���´�
			//�� ���̰� ���� ���� ���̺��� ũ�ٸ� �浹�Ѵ� 
			if (d[x][y] != -1 && now - d[x][y] <= len) {
				cout << now << endl;
				return 0;
			}
			d[x][y] = now;
		}
		if (ch == 'L') {
			dir = (dir + 3) % 4;
		}
		else {
			dir = (dir + 1) % 4;
		}
	}
	return 0;
}