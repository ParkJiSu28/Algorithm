#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;
int TestCase;
vector< vector<int> > adj;
vector<int> seen, order;


void makeGraph(const vector<string>& word) {
	adj = vector< vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < word.size(); j++) {
		int i = j - 1;
		int len = min(word[i].size(), word[j].size());
		for (int k = 0; k < len; k++) {
			if (word[i][k] != word[j][k]){
				int a = word[i][k] - 'a';
				int b = word[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
		}
	}
}
void dfs(int here) {
	seen[here] = 1;
	for (int there = 0; there < adj.size(); ++there) 
		if (adj[here][there] && !seen[there]) 
			dfs(there);
	order.push_back(here);
	
}

vector<int> topologicalSort() {
	int n = adj.size();
	seen = vector<int>(n, 0);
	order.clear();
	for (int i = 0; i < n; ++i) if (!seen[i]) dfs(i);
	reverse(order.begin(), order.end());
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (adj[order[j]][order[i]]) {
				return vector<int>();
			}
		}
	}
	return order;
}


int main() {
	cin >> TestCase;
	for (int T_case = 0; T_case < TestCase; T_case++) {
		int word_count;
		cin >> word_count;
		vector<string>word(word_count);
		for (int word_case = 0; word_case < word_count; word_case++) {
			cin >> word[word_case];
			
		}
		makeGraph(word);
		vector<int> answer=topologicalSort();
		if (answer.empty()) {
			cout << "INVALID HYPOTHESIS";
		}
		else {
			for (int i = 0; i < answer.size(); i++) {
				cout << (char)(answer[i] + 'a');

			}
			cout << endl;
		}
	}
	return 0;
}