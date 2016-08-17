#include<iostream>
#include<algorithm>
using namespace std;

int N;
int mat[500][2];
int mem[500][500];


int Go(int s, int e) {
	if (mem[s][e] != 0) return mem[s][e];
	if (s == e) return 0;

	long long temp = INT32_MAX;
	for (int i = s; i < e; i++)
		temp = min(temp, Go(s,i)+ Go(i+1, e) + mat[s][0]* mat[i+1][0]* mat[e][1] * 1LL);

	return mem[s][e] = temp;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> mat[i][0] >> mat[i][1];

	cout << Go(0, N - 1);
}