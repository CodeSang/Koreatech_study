#include<iostream>
using namespace std;

int main() {
	
	int testCase;
	cin >> testCase;

	while(testCase--){
	
		int N;
		cin >> N;
		
		int mat[2][16] = { 0 };
		mat[1][0] = 1;
		mat[1][3] = 1;
		mat[1][6] = 1;
		mat[1][12] = 1;
		mat[1][15] = 1;
		
		for (int i = 2; i <= N; i++)
		{
			mat[i % 2][0] = mat[(i + 1) % 2][15];

			mat[i % 2][1] = mat[(i + 1) % 2][14];
			mat[i % 2][2] = mat[(i + 1) % 2][13];
			mat[i % 2][4] = mat[(i + 1) % 2][11];
			mat[i % 2][8] = mat[(i + 1) % 2][7];

			mat[i % 2][10] = mat[(i + 1) % 2][5];
			mat[i % 2][5]  = mat[(i + 1) % 2][10];
			mat[i % 2][9] = mat[(i + 1) % 2][6];

			mat[i % 2][3]  = mat[(i + 1) % 2][12] + mat[(i + 1) % 2][15];
			mat[i % 2][6]  = mat[(i + 1) % 2][9] + mat[(i + 1) % 2][15];
			mat[i % 2][12] = mat[(i + 1) % 2][15] + mat[(i + 1) % 2][3];

			mat[i % 2][11] = mat[(i + 1) % 2][4] + mat[(i + 1) % 2][7];
			mat[i % 2][13] = mat[(i + 1) % 2][2] + mat[(i + 1) % 2][14];
			mat[i % 2][7]  = mat[(i + 1) % 2][8] + mat[(i + 1) % 2][11] + mat[(i + 1) % 2][14];
			mat[i % 2][14] = mat[(i + 1) % 2][1] + mat[(i + 1) % 2][7] + mat[(i + 1) % 2][13];

			mat[i % 2][15] = mat[(i + 1) % 2][0] + mat[(i + 1) % 2][3] + mat[(i + 1) % 2][6] + mat[(i + 1) % 2][12] + mat[(i + 1) % 2][15];
		}
		
		cout << mat[N%2][15] << '\n';
	}
}