#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;
int mat1[1001];
int mat2[1001];

int mem[1001][1001];

int Go(int n, int m) {

	if (n < m) return 1000000007;
	else if (m < 0) return 0;

	int &temp = mem[n][m];
	if (temp != -1) return temp;
	temp = 1000000007;

	for (int i = n; i >= m; i--)
		temp = min(temp, Go(i - 1, m - 1) + abs(mat1[i] - mat2[m]));
	
	return temp;
}


int main() {
	memset(mem, -1, sizeof(mem));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> mat1[i];
	for (int i = 0; i < M; i++)
		cin >> mat2[i];

	sort(mat1, mat1 + N);
	sort(mat2, mat2 + M);

	if (N < M)
	{
		swap(N, M);
		swap(mat1, mat2);
	}

	cout << Go(N-1,M-1)<<endl;
}