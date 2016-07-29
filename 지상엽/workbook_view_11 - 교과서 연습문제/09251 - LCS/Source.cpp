#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int DP[1001][1001];
int main() {
	string A,B;

	cin >> A;
	cin >> B;

	int N, M;
	N = A.length();
	M = B.length();

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			if (A[i - 1] == B[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
			else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	
	cout << DP[N][M] << endl;
	return 0;
}