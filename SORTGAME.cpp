#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<map>
#include<queue>
using namespace std;
//key : 모든 n에 대하여 정렬된 배열에서 다른 모든 상태까지 도달하는데 필요한 뒤집기 연산의 수를 BFS로 계산
//그 다음 입력 받은 배열들의 숫자들의 상대적 크기를 유지하면서 [0~n-1]범위의 값을 갖도록 바꾼다.
map<vector<int>, int>toSort;
//map<vector<int>, int>::iterator iter;
//[0~n-1]의 모든 순열에 대해 toSort를 계산해 저장한다.
void precalc(int n) {
	vector<int>perm(n);//0을 기본값으로 가진 n개의 벡터생성.
	for (int i = 0; i < n; ++i) perm[i] = i; //perm의 기본값 삽입.
	queue<vector<int> >q; // perm을 정점으로 해 bfs을 돌 queue생성
	q.push(perm);
	toSort[perm] = 0; //처음 상태에서 value값 지정
	while (!q.empty()) {
		vector<int>here = q.front();//perm값을 리버스할 때 저장할 배열 생성.
		q.pop();
		int cost = toSort[here];//뒤집기 연산의 횟수를 저장하는 변수,toSort의 value값을 사용
		for (int i = 0; i < n; ++i) {
			for (int j = i + 2; j <= n; ++j) {
				reverse(here.begin() + i, here.begin() + j);//뒤집기 연산
				if (toSort.count(here) == 0) {//here 순열에서 원소갯수가 0이면 뒤집기 연산을 아직 안했다는 것이므로
					toSort[here] = cost + 1; //앞서 뒤집기연산횟수인 cost+1을 value값으로 삽입
					q.push(here); // 뒤집은 순열 queue 에 삽입
				}
				reverse(here.begin() + i, here.begin() + j);//뒤집기 연사한 순열을 다시 뒤집어 원상태 복귀
			}
		}
	}

}

int solve(const vector<int>& perm) {
	//perm을 [0~n-1]의 순열로 변환
	int n = perm.size();
	vector<int>fixed(n); //n개원소가 기본값 0을가지는 벡터생성
	for (int i = 0; i < n; ++i) {
		int smaller = 0;
		for (int j = 0; j < n; ++j) 
			if (perm[j] < perm[j]) //perm순열의 대소를 비교해 연산 횟수를 구한다.
				++smaller;// 배열을 정렬하는데 필요한 연산횟수는 정렬된 배열을 원래배열로 만드는 횟수랑 동일하다.
		fixed[i] = smaller;
		
	}
	return toSort[fixed];
}

int main() {
	int TestCase;
	cin >> TestCase;
	precalc(8);
	while (TestCase--)
	{
		int length;
		cin >> length;
		vector<int>perm(length);
		for (int i = 0; i < length; i++) {
			cin >> perm[i];
		}
		cout << solve(perm)<<endl;	
	}
}