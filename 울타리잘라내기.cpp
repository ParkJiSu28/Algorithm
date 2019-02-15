#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int T;
int h[20001];


int max_ret(int left,int right) {
	if (left == right) {
		return h[left];
	}
	int mid = (left + right) / 2;
	int ret = max(max_ret(left, mid), max_ret(mid + 1, right));
	int low = mid;
	int high = mid + 1;
	int height = min(h[low], h[high]); //���߿� �����Ÿ� ���̷� ���� �׷��� ���簢���� �����ȴ�.
	ret = max(ret, height * 2);//��ġ�� �κ��� �ʺ� 2�� ������� ó���� ����Ѵ�.
	//������� ��Ÿ�� ��ü�� ���������� ���̰� ū������ Ȯ���� ������.
	while (left < low || high < right) {
		if (high < right && (low == left || h[low - 1] < h[high + 1])) {
			//���� �ȿ� �ְ� low���� �������� ������ ���̰� ū������ Ȯ��
			++high;
			height = min(height, h[high]);// �簢�� ������ ������ϹǷ� ������ ���̷�
		}
		else {// �ݴ�� ���� ���̰� �� ũ�ٸ� �������� Ȯ��
			--low;
			height = min(height, h[low]);
		}
		//Ȯ���� �Ϸ���Ŀ� �簢���� ����
		ret = max(ret, height*(high - low+1));
		//��� ȣ���� �ذ��鼭 ������ �ִ� ret����  ���� �簢���� ���̸� ���� ū���� ����
	}
	return ret;
}

int main() {
	cin >> T;
	while (T!=0) {
		int fense;
		cin >> fense;
		memset(h, 0, sizeof(h));
			for (int i = 0; i < fense; i++) {
				int fense_h;
				cin >> fense_h;
				h[i] = fense_h;
			}
			int answer = max_ret(0, fense-1);
			cout << answer << "\n";
			T--;
	}
	return 0;
}