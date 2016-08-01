#include<iostream>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int mat[2][15] = { 0 };
		int N, K;
		cin >> N >> K;
		for (int j = 1; j <= K; j++)
			mat[0][j] = j;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= K; j++)
			{
				mat[i % 2][j] = mat[i % 2][j-1] + mat[(i + 1)% 2][j];
			}
		}

		cout << mat[(N) % 2][K] << endl;
	}
}