#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;
int mat[102];
int sum[110];
int mem[100][55];
bool c[101][101];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> mat[i];
		sum[i] = sum[i - 1] + mat[i];
	}
}

int Go(int idx, int cnt)
{
	if (cnt == 0)	return 0;
	if (idx < 1)	return -3400000;

	if (c[idx][cnt]) return mem[idx][cnt];
	c[idx][cnt] = true;

	int temp = Go(idx-1,cnt);
	for (int i = idx; i > 0; i--) 
		temp = max(temp, Go(i-2,cnt-1) + sum[idx] - sum[i-1]);

	return mem[idx][cnt] = temp;
}

void output() {
	cout << Go(N, M) << endl;
}

int main() {
	input();
	output();
}