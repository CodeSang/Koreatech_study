#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int N;
int mat[501];
int mem[501][501];
int sum[501];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> mat[i];
		sum[i] = sum[i-1] + mat[i];
	}
}

int process(int s, int e) {
	if (mem[s][e] != 0)return mem[s][e];
	if (s == e) return mem[s][e] = 0;
	if (e - s + 1 == 2) return mem[s][e] = mat[s] + mat[e];

	int temp = INT32_MAX;
	int sumA = sum[e] - sum[s - 1];

	for (int i = s; i < e; i++)
		temp = min(temp, process(s, i) + process(i + 1, e) + sumA);

	return mem[s][e] = temp;
}

void output() {
	cout << process(1, N) << '\n';
}

int main() {

	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		memset(mem, 0, sizeof(mem));
		input();
		output();
	}
}