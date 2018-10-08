#include<iostream>
#include <cstring> 

using namespace std;



const int MAX = 100000 + 1;



int N, cnt;

int want[MAX];

bool visited[MAX];

bool done[MAX];



void DFS(int nodeNum)

{

	visited[nodeNum] = true;



	int next = want[nodeNum];

	if (!visited[next])

		DFS(next);

		else if (!done[next])

	{

		//팀원을 모두 센다

		for (int i = next; i != nodeNum; i = want[i]) {
			//cout <<"i:"<<i<<"nodeNum:"<<nodeNum<< "want:"<<want[i] << endl;;
			cnt++;
			
		}
		cnt++; 	}



	done[nodeNum] = true; 
}



int main(void)

{

	int T;

	cin >> T;



	for (int i = 0; i < T; i++)

	{

		memset(visited, false, sizeof(visited));

		memset(done, false, sizeof(done));

		cin >> N;



		for (int j = 1; j <= N; j++)

			cin >> want[j];



		cnt = 0;

		for (int j = 1; j <= N; j++)

			if (!visited[j])

				DFS(j); 

		cout << N - cnt << endl;

	}

	return 0;

}
