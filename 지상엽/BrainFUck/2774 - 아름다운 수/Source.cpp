#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int T;
	cin >> T;
	while (T--) {
		int mat[10] = { 0 };
		int temp;
		cin >> temp;
		while (temp)
		{
			mat[temp % 10] = 1;
			temp /= 10;
		}
		int maxi = 0;
		for (int i = 0; i < 10; i++)
			maxi += mat[i];
		cout << maxi << endl;
	}
}
