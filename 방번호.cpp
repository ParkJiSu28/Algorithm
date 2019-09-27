#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>

using namespace std;



int charToInt(char c)
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	return arr[c - '0'];
}

int main() {
	string temp;
	getline(cin, temp);
	vector<long long>digit;
	for (int i = 0; i < temp.length(); i++) {
		digit.push_back(charToInt(temp[i]));
	}
	int num[10];
	memset(num, 0, sizeof(num));
	for (int i = 0; i < digit.size(); i++) {
		if (digit[i] == 0)num[0]+=1;
		if (digit[i] == 1)num[1]+=1;
		if (digit[i] == 2)num[2]+=1;
		if (digit[i] == 3)num[3]+=1;
		if (digit[i] == 4)num[4]+=1;
		if (digit[i] == 5)num[5]+=1;
		if (digit[i] == 6)num[6]+=1;
		if (digit[i] == 7)num[7]+=1;
		if (digit[i] == 8)num[8]+=1;
		if (digit[i] == 9)num[9]+=1;
	}
	int si_ni = (num[6]+ num[9]);
	if (si_ni % 2 == 1) {
		si_ni += 1;
		num[6] = si_ni/2;
		num[9] = 0;
	}
	else {
		num[6] = si_ni/2;
		num[9] = 0;
	}
	long long max = 0;
	for (int i = 0; i < 9; i++) {
		if (num[i] > max)max = num[i];
	}
	cout << max << endl;
	return 0;
}