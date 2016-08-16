#include<iostream>
#define LIM 1000000000
using namespace std;

int N, K;
int dp[202][202]; // N,K

int Go(int n, int k)
{
	if (k == 1) return 1;
	int& temp = dp[n][k];
	if (temp != 0) return temp;
	for (int i = 0; i <= n; i++)
		temp = (temp + Go(n - i, k - 1) ) % LIM;
	return temp;
}

int main() {
	cin >> N >> K;
	cout << Go(N, K) << endl;
}