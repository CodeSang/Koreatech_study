#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


int N;
int mat[16][16];

long long minm = INT64_MAX;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> mat[i][j];
}

int DP[1 << 16][16];
int st = 0;

int memorize(int now, unsigned int dst) {
	

	if (dst == 0) // 예외처리.
		if (mat[now][st] != 0)
			return mat[now][st];
		else
			return 16000000;

	if (DP[dst][now] != -1)
		return DP[dst][now];

	int mi = 16000000;
	for (int i = 0; i < N; i++)
	{
		unsigned int temp = ((1 << i) | dst);
		if ((temp == dst) && (mat[now][i] != 0))
		{
			mi = min(mi, mat[now][i] + memorize(i,  (dst ^ (1<<i)) ));
		}
	}

	return DP[dst][now] = mi;
}

void process() {

	memset(DP, -1, sizeof(DP));
	unsigned int temp = (1 << N) - 2;
	minm = memorize(0, temp);
}

void output() {
	cout << minm << endl;
}

int main() {
	input();
	process();
	output();
}