#include<iostream>
using namespace std;

int N, M;
int mat[301][301] = { 0 };
int mem[302][302] = { 0 };

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> mat[i][j];


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			mem[i][j] = mat[i-1][j-1] + mem[i - 1][j] + mem[i][j - 1] - mem[i - 1][j - 1];	

	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int Ax, Ay, Bx, By;
		cin >> Ax >> Ay >> Bx >> By;

		Ax--; Ay--;
		cout<< mem[Bx][By] - mem[Ax][By] - mem[Bx][Ay] + mem[Ax][Ay] << endl;
	}

}