//#include<iostream>
//using namespace std;
//int decimal[3];
//
//int main() {
//	int N;
//	cin >> N;
//	int hansu;
//	int count;
//	int number;
//	for (int i = 0; i <= N; i++) {
//		if (i < 100)hansu=i;
//		else if (i == 1000)break;
//		number = i;
//		count = 0;
//		while (number > 0) {
//			decimal[count] = number % 10;
//			number /= 10; count++;
//		}
//		if (decimal[0] - decimal[1] == decimal[1] - decimal[2])hansu++;
//	}
//	cout << hansu;
//}
