#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

string tobni[4];
int dir[4];

int solution() {
	int answer = 0;

	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			if (tobni[0][0] == '1')answer++;
		}
		else if (i == 1) {
			if (tobni[1][0] == '1')answer=answer+2;
		}
		else if (i == 2) {
			if (tobni[2][0] == '1')answer = answer + 4;
		}
		else if (i == 3) {
			if (tobni[3][0] == '1')answer = answer + 8;
		}
	}
	return answer;
}


int main() {
	for (int i = 0; i < 4; i++) {
		cin>>tobni[i];
	}
	int count;
	cin >> count;
	
	for (int i = 0; i < count; i++) {
		int tobninumber;
		int tempdir;
		memset(dir, 0,sizeof(dir));

		cin >> tobninumber >> tempdir;
		tobninumber -= 1;
		dir[tobninumber] = tempdir;
		//¿ÞÂÊ Åé´Ï¹ÙÄû °Ë»ç
		for (int i = tobninumber-1; i >= 0 ; i--) {
			if (tobni[i+1][6] != tobni[i][2]) {
				dir[i] = -dir[i+1];
			}
			else break;
		}//¿À¸¥ÂÊ Åé´Ï¹ÙÄû °Ë»ç
		for (int i = tobninumber+1; i < 4; i++) {
			if (tobni[i][6] != tobni[i-1][2]) {
				dir[i] = -dir[i-1];
			}
			else break;
		}
		//Åé´Ï¹ÙÄû µ¹¸®±â
		for (int i = 0; i < 4; i++) {
			if (dir[i] == 0)continue;
			else if (dir[i] == 1) {
				char temp = tobni[i][7];
				for (int j = 7; j >= 1; j--) {
					tobni[i][j] = tobni[i][j - 1];
				}
				tobni[i][0] = temp;
			}
			else if (dir[i] == -1) {
				char temp = tobni[i][0];
				for (int j = 0; j < 7; j++) {
					tobni[i][j] = tobni[i][j + 1];
				}
				tobni[i][7] = temp;
			}
		}
	}

	int ans = solution();
	cout << ans<<endl;
	return 0;
}