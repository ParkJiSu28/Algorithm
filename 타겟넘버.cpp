#include <string>
#include <vector>
#include<iostream>
using namespace std;
int total;

void dfs(vector<int>numbers, int target, int sum, int n) {
	if (n >= numbers.size()) {
		if (sum == target)total++;
		return;
	}
	dfs(numbers, target, sum + numbers[n], n + 1);
	dfs(numbers, target, sum - numbers[n], n + 1);
}
int solution(vector<int> numbers, int target) {
	dfs(numbers, target, numbers[0], 1);
	dfs(numbers, target, -numbers[0], 1);

	int answer = total;
	return answer;
}