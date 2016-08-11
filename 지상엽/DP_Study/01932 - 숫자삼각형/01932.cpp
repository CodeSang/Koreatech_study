#include<iostream>
#include<algorithm>
using namespace std;

int N;
int mat[501][501];
int mem[501][501];


int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> mat[i][j];

	for (int i = 0; i < N; i++)
		mem[N - 1][i] = mat[N - 1][i];

	for (int i = N-2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			mem[i][j] = max(mem[i+1][j], mem[i + 1][j+1]) + mat[i][j];	

	cout << mem[0][0] << endl;
}
