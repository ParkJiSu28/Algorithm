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
	int height = min(h[low], h[high]); //둘중에 작은거를 높이로 설정 그래야 직사각형이 성립된다.
	ret = max(ret, height * 2);//겹치는 부분인 너비 2인 사격형을 처음에 고려한다.
	//사격형이 울타리 전체를 덮을때까지 높이가 큰쪽으로 확장해 나간다.
	while (left < low || high < right) {
		if (high < right && (low == left || h[low - 1] < h[high + 1])) {
			//범위 안에 있고 low값을 기준으로 오른쪽 높이가 큰쪽으로 확장
			++high;
			height = min(height, h[high]);// 사각형 기준을 맞춰야하므로 낮은걸 높이로
		}
		else {// 반대로 왼쪽 높이가 더 크다면 그쪽으로 확장
			--low;
			height = min(height, h[low]);
		}
		//확장이 완료된후에 사각형의 넓이
		ret = max(ret, height*(high - low+1));
		//재귀 호출을 해가면서 기존에 있던 ret값과  구한 사각형의 넓이를 비교해 큰쪽을 저장
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